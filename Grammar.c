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

Production newProduction(Grammar g){
	Production p=malloc(sizeof(production));
	p->productive=false;
	p->visited=false;
	addProduction(g,p);
	return p;
}

void addProduction(Grammar g, Production p){
	addToList(p,g->productions);
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
	//printf("%c is T? %d\n",c,containsChar(g->terminals,c));
	return containsChar(g->terminals,c);
}

boolean isNonTerminal(Grammar g, char c){
	//printf("%c is NT? %d\n",c,containsChar(g->nonTerminals,c));
	return containsChar(g->nonTerminals,c);
}

void printGrammar(Grammar g){
	char * stringy;
	char * buffer = malloc(50);
	stringy = strdup("====================================================\nGramatica ");
	sprintf(buffer, "%s\nSimbolos no terminales: \n", g->name);
	//stringy = concat(stringy, g->name);
	//stringy = concat(stringy, "\nSimbolos no terminales: ");
	int i;
	stringy = concat(stringy, buffer);
	for(i = 0; i < strlen(g->nonTerminals); i++){
		cleanBuffer(buffer, 50);
		sprintf(buffer, "%c ", g->nonTerminals[i]);
		stringy = concat(stringy, buffer);
	}
	stringy = concat(stringy, "\nSimbolos terminales: \n");
	for(i = 0; i < strlen(g->terminals); i++){
		cleanBuffer(buffer, 50);
		sprintf(buffer, "%c ", g->terminals[i]);
		stringy = concat(stringy, buffer);
	}
	cleanBuffer(buffer, 50);
	sprintf(buffer, "\nSimbolo inicial:\n%c\nLa gramatica es valida y es de ", g->dist );
	stringy = concat(stringy, buffer);
	printf("%s\n", stringy);
	printf("Producciones\n");
	Element e;
	Production p;
	FOR_EACH(e, g->productions){
		p = (Production)e->data;
		printf("%c->%s\n", p->from, p->word);
	}
}

void printProduction(Production p){	
	if(p==NULL){
		printf("%c->%d, productive:%d\n",p->from,p,p->productive);
	}else{
		printf("%c->%s, productive:%d\n",p->from,p->word,p->productive);
	}
}
