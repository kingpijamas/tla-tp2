#include "Grammar.h"

Grammar newGrammar(){
	Grammar g=malloc(sizeof(grammar));
	if(g==NULL){
		newInsufficientMemoryException("Grammar");
	}
	g->nonTerminals = malloc(sizeof(char)*27);
	g->terminals = malloc(sizeof(char)*27);
	g->productions=newList();
	initList(g->productions);
	return g;
}

void addNonTerminal(Grammar g, char * from){
	if(g->nonTerminals!=NULL && containsChar(g->nonTerminals, *from)){
		printf("No terminal duplicado.\n No se acepta el lenguaje.\n");
		exit(1);
	}
	g->nonTerminals=concat(g->nonTerminals,from);
}

void addTerminal(Grammar g, char * from){
	if(g->terminals!=NULL && containsChar(g->terminals, from[0])){
		printf("Terminal duplicado.\n No se acepta el lenguaje.\n");
		exit(1);
	}
	g->terminals=concat(g->terminals,from);
}


void addProduction(Grammar g, Production p){
	addToList(p,g->productions);
}

Production newProduction(Grammar g){
	Production p=malloc(sizeof(production));
	p->productive=false;
	p->visited=false;
	addProduction(g,p);
	return p;
}

Production getLastProduction(Grammar g){
	return ((Production)(g->productions->pLast)->data);
}

void removeNonTerminal(Grammar g, char c){
	int i = indexOf(g->nonTerminals, c);
	int j;
	for(j = i; j < strlen(g->nonTerminals)-1; j++){
		g->nonTerminals[j] = g->nonTerminals[j+1];
	}
	g->nonTerminals[strlen(g->nonTerminals)-1] = 0;
}

void addWord(Production p, char * word){
	p->word=concat(p->word,word);
}

boolean isTerminal(Grammar g, char c){
	return containsChar(g->terminals,c);
}

boolean isNonTerminal(Grammar g, char c){
	return containsChar(g->nonTerminals,c);
}
