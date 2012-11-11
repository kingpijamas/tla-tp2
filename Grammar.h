#ifndef Grammar_h
#define Grammar_h

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "Grammar.h"
#include "LinkedList.h"

typedef struct production{
	char from;
	char * word;
}production;

typedef production * Production;

typedef struct grammar{
	char * name;
	char dist;
	char * nonTerminals;
	char * terminals;
	List productions;
}grammar;

typedef grammar * Grammar;
Grammar newGrammar();
void addNonTerminal(Grammar g, char * from);
void addTerminal(Grammar g, char * from);
void addProduction(Grammar g, Production p);
Production newProduction(Grammar g);
Production getLastProduction(Grammar g);
void removeNonTerminal(Grammar g, char c);

#endif
