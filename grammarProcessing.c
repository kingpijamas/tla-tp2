#include "grammarProcessing.h"

GrammarErrorCodes validateGrammar(Grammar g){
	//Validacion que los "from" esten contenidos en NoTerm y el dist esta en algun from	
	boolean useDist = false;
	Element e;
	Production p;
	int i=0;
	if(!containsChar(g->nonTerminals,g->dist)){
		/*distinguido no es noTerm*/
		return INVALID_DIST;
	}
	FOR_EACH(e,g->productions){
		p=(Production)e->data;
		if(p->from == g->dist){
			useDist = true;
		}
		if(!containsChar(g->nonTerminals,p->from)){
			// From no esta en non terminals
			return INVALID_FROM;		
		}
		if(p->word!=NULL){//la palabra es lambda
			while(p->word[i]!='\0'){
				if(!isTerminal(g,p->word[i])&&!isNonTerminal(g,p->word[i])){
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
	FOR_EACH(e,g->productions){
		p=(Production)e->data;		
		List visited=newList();
		initList(visited);
		if(p->productive!=true){
		
		}
	}
	
	while(){
		
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
		if(isNonTerminal(p->word[i])==true){
			if(!isProductiveNonTerminal(g,p,viisted,p->word[i])==true){	
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
			if(aux->from==p->from && isVisited(aux,visited)==true){
				addToList(aux,visited);
				if(isProductive(g, p, visited)){
					return true;
				}
				//TODO: forma de remover el ultimo de la lista
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
