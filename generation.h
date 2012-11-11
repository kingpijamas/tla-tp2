/*
 * generation.h
 *
 *  Created on: Nov 9, 2012
 *      Author: apierri
 */

#ifndef GENERATION_H_
#define GENERATION_H_

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "Grammar.h"
#include "LinkedList.h"

int getTerminalCount(char * string);
void makeASDR(Grammar g);
char * insertLine(char * string, char * line);
char * parseProductions(char from, char * word);
char * getFirstTerminals(char * word);
void writeC(char * text);
void writeCChar(char character);
void writeH(char * text);
void writeHChar(char character);



#endif /* GENERATION_H_ */
