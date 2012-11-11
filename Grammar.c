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
		printf("Duplicate non terminal detected.\n Program terminated.\n");
		exit(1);
	}
	g->nonTerminals=concat(g->nonTerminals,from);
}

void addTerminal(Grammar g, char * from){
	if(g->terminals!=NULL && containsChar(g->terminals, from[0])){
		printf("Duplicate terminal detected.\n Program terminated.\n");
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

