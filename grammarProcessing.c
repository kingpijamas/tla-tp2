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
		printProduction(p);
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
		if(isProductive(g,p,visited)){				
			addToList((Production)e->data,aux);
		}
	}
	printf("Pre-remocion\n");
	FOR_EACH(e,g->productions){
		printProduction((Production)e->data);
	}
	g->productions=aux;
	printf("\nFinalmente\n");
	FOR_EACH(e,g->productions){
		printProduction((Production)e->data);
	}
	return g;
}

boolean isProductive(Grammar g,Production p,List visited){
	int i;
	if(p->productive==true){
		return true;
	}
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
	return true;
}

boolean isProductiveNonTerminal(Grammar g, Production p, List visited, char nt){
		Element e;
		Production aux;
		FOR_EACH(e,g->productions){
			aux=(Production) e->data;
			if(aux->from==nt && isVisited(aux,visited)!=true){
				visit(aux,visited);
				if(isProductive(g, aux, visited)){
					return true;
				}
				unvisit(aux,visited);
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
			removeElemFromList(e,visited);
		}
		e=e->prev;
	}
	return;
}
