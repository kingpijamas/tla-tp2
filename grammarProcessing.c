#include "grammarProcessing.h"

GrammarErrorCodes validateGrammar(Grammar g){
	//Validacion que los "from" esten contenidos en NoTerm y el dist esta en algun from	
	boolean useDist = false;
	Element e;
	Production p;
	int i=0;
	if(!containsChar(g->nonTerminals,g->dist)){//distinguido no es noTerm
		return INVALID_DIST;
	}
	FOR_EACH(e,g->productions){
		p=(Production)e->data;
		if(p->from == g->dist){
			useDist = true;
		}
		if(!containsChar(g->nonTerminals,p->from)){// From no esta en non terminals
			return INVALID_FROM;		
		}
		while(p->word[i]!='\0'){
			if(!isTerminal(g,p->word[i])&&!isNonTerminal(g,p->word[i])){//todo simbolo no lambda TIENE que ser o T o NT
				return INVALID_SYMBOL;
			}
			i++;
		}
	}
	if(useDist == false){
		return DIST_NOT_USED;
	}
	return NO_ERROR;
}

Grammar removeUnproductiveProductions(Grammar g){
	Element e;
	Production p;
	List visited=newList();
	List aux=newList();
	FOR_EACH(e,g->productions){
		p=(Production)e->data;
		initList(visited);
		printf("----------------\n");
		printProduction(p);
		printf("\n");
		if(isProductive(g,p,visited)){
			printf("\n\n\n");
			addToList((Production)e->data,aux);
		}
	}
	g->productions=aux;
	return g;
}

boolean isProductive(Grammar g,Production p,List visited){
	int i;
	if(p->productive==true){
		return true;
	}
	p->visited=true;
	i=0;
	while(p->word[i]!='\0'){
		if(isNonTerminal(g,p->word[i])==true){
			if(isProductiveNonTerminal(g,p,visited,p->word[i])!=true){	
				return false;
			}
		}
		i++;
	}
	p->productive=true;
	p->visited=false;
	return true;
}

boolean isProductiveNonTerminal(Grammar g, Production p, List visited, char nt){
		Element e;
		Production aux;
		FOR_EACH(e,g->productions){
			aux=(Production) e->data;
			if(aux->from==nt && aux->visited==false){
				printf("--\nestoy en ispnt, con %c\n",nt);
				printf("vengo de:");
				printProduction(p);
				printf("me fijo en:");
				printProduction(aux);
				printf("producciones:");
				printList(g->productions);
				aux->visited=true;
				//visit(aux,visited);
				if(isProductive(g, aux, visited)){
					aux->visited=false;
					//unvisit(aux,visited);
					return true;
				}
				aux->visited=false;
				//unvisit(aux,visited);
			}
		}
		return false;
}

boolean isVisited(Production p,List visited){
	Element e;
	FOR_EACH(e,visited){
		if(((Production)e->data)==p){
			return true;
		}
	}
	return false;
}

void visit(Production p, List visited){
	addToList(p,visited);
}

void unvisit(Production p, List visited){
	Element e=visited->pLast;
	Production aux;
	while(e->prev!=NULL){
		aux=(Production)e->data;
		if(aux==p){
			printf("busco p:(%d) ",p);
			printProduction(p);
			printf("remover:(%d) ",aux);
			printProduction(aux);
			removeElemFromList(e,visited);
		}
		e=e->prev;
	}
	return;
}

void printList(List l){
	Element e;
	printf("\t(");
	FOR_EACH(e,l){
		if(((Production)e->data)->word==NULL){
			printf("%c->\\",((Production)e->data)->from);
		}else{
			printf("%c->%s",((Production)e->data)->from,((Production)e->data)->word);
		}
		if(((Production)e->data)->visited==true){
			printf("(X),");
		}
	}
	printf(")\n");
}
