#ifndef grammarProcessing_h
#define grammarProcessing_h

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "LinkedList.h"
#include "Grammar.h"

typedef enum {
	INVALID_DIST=!NO_ERROR,INVALID_FROM,INVALID_SYMBOL,DIST_NOT_USED
} GrammarErrorCodes;

GrammarErrorCodes validateGrammar(Grammar g);
Grammar removeUnproductiveProductions(Grammar g);
boolean isProductive(Grammar g,Production p,List visited);
boolean isProductiveNonTerminal(Grammar g, Production p, List visited, char nt);
boolean isVisited(Production p,List visited);
void visit(Production p, List visited);
void unvisit(Production p, List visited);
void printProductionList(List l);

#endif
