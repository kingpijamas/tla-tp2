
#ifndef ASDR_H_
#define ASDR_H_
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

char * S(char * obj, char * prev);

char * S(char * obj, char * prev);

char * U(char * obj, char * prev);

char * U(char * obj, char * prev);

char * V(char * obj, char * prev);

char * V(char * obj, char * prev);

char * T(char * obj, char * prev);

char * T(char * obj, char * prev);

char * T(char * obj, char * prev);

boolean goodDirection(char * production, char * obj);

char * expandFirstNonTerminal(char * prev, char * pattern);

char getFirstNonTerminal(char * text);
#endif