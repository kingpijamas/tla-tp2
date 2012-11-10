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
		if(p->word!=NULL){//la palabra no es lambda
			while(p->word[i]!='\0'){
				if(!isTerminal(g,p->word[i])&&!isNonTerminal(g,p->word[i])){//todo simbolo no lambda TIENE que ser o T o NT
					return INVALID_SYMBOL;
				}
				i++;
			}
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
	printProductionList(g->productions);	
	List visited=newList();
	List toRemove=newList();
	FOR_EACH(e,g->productions){
		p=(Production)e->data;
		initList(visited);
		if(!isProductive(g,p,visited)){
			addToList(e,toRemove);
		}
	}
	printf("Finalmente\n");
	FOR_EACH(e,g->productions){
		printProduction((Production)e->data);
	}
	FOR_EACH(e,toRemove){
		removeElemFromList(e,g->productions);
	}
	return g;
}

boolean isProductive(Grammar g,Production p,List visited){
	//printf("----------IS PRODUCTIVE?---------\n");
	int i;
	//printProduction(p);
	//printf("visited");
	printProductionList(visited);
	if(p->productive==true){
		return true;
	}
	i=0;
	while(p->word[i]!='\0'){
		if(isNonTerminal(g,p->word[i])==true){
			//printf("%c es NT\n",p->word[i]);
			if(isProductiveNonTerminal(g,p,visited,p->word[i])!=true){	
				printProduction(p);
				return false;
			}
		}
		i++;
	}
	p->productive=true;
	//printProduction(p);
	return true;
}

boolean isProductiveNonTerminal(Grammar g, Production p, List visited, char nt){
		//printf("----------IS PRODUCTIVE NT?---------\n");
		Element e;
		Production aux;
		FOR_EACH(e,g->productions){
			aux=(Production) e->data;
			/*printf("p:");
			printProduction(p);						
			printf("aux:");
			printProduction(aux);
			printf("\t\tis aux visited?:%d\n",isVisited(aux,visited));
			printf("\t\tentro:%d\n",(aux->from==p->from && isVisited(aux,visited)!=true));*/
			if(aux->from==p->from && isVisited(aux,visited)!=true){
				visit(aux,visited);
				//printf("visited");				
				//printProductionList(visited);
				//printf("\t\tnow, is aux visited?:%d\n",isVisited(aux,visited));				
				if(isProductive(g, aux, visited)){
					return true;
				}
				unvisit(aux,visited);
				//printf("visited after");				
				//printProductionList(visited);
				//printf("\t\tnow now, is aux visited?:%d\n",isVisited(aux,visited));
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
	while(e->prev!=NULL){
		if(((Production)e->data)==p){
			removeElemInList(e,visited);
		}
		e=e->prev;
	}
	return;
}

void printProductionList(List l){
	Element e;
	Production p;
	printf("(\n");
	FOR_EACH(e,l){
		p=(Production)e->data;
		if(p==NULL){
			printf("\t%c->%d(%d)\n",p->from,p,p->productive);
		}else{
			printf("\t%c->%s(%d)\n",p->from,p->word,p->productive);
		}
	}
	printf(")\n");
}
