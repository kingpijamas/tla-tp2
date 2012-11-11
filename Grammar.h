#ifndef Grammar_h
#define Grammar_h

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "LinkedList.h"

typedef struct production{
	char from;
	char * word;
	boolean productive;
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

Grammar newGrammar();
void addNonTerminal(Grammar g, char * from);
void addTerminal(Grammar g, char * from);
Production newProduction(Grammar g);
void addProduction(Grammar g, Production p);
Production getLastProduction(Grammar g);
void removeNonTerminal(Grammar g, char c);
void addWord(Production p, char * word);
boolean isTerminal(Grammar g, char c);
boolean isNonTerminal(Grammar g, char c);
void printGrammar(Grammar g);
void printProduction(Production p);

#endif
