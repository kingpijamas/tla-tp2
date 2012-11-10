%{
	#include "tp.h"

	Grammar g;
	Production p;
	Production aux;
%}

digit	[0-9]
letter	[a-zA-Z]
upper	[A-Z]
lower	[a-z]
lambda	\\
blank	[ \t\n]

%option noyywrap

%s GRAMNAME
%s START
%s DIST
%s NONTERMINALS
%s TERMINALS
%s PRODUCTIONFROM
%s PRODUCTIONTO
%s FROMPIPE
%s PRODUCTIONSEPARATOR

%%
{blank}+ ;

<INITIAL>{letter}([^ \n\t])* {g = newGrammar(); g->name=strdup(yytext); BEGIN START;}
<START>={blank}*\({blank}*\{ {printf("I'm in'\n");BEGIN NONTERMINALS;}
<NONTERMINALS>{upper}{blank}*, {printf("Estoy en nonterminals\n");addNonTerminal(g,stringify(yytext[0]));}
<NONTERMINALS>{upper}{blank}*\}{blank}*,{blank}*\{ {printf("Estoy en nonterminals\n");addNonTerminal(g,stringify(yytext[0]));BEGIN TERMINALS;}

<TERMINALS>{lower}{blank}*, {printf("Estoy en terminals\n");addTerminal(g,yytext);}
<TERMINALS>{lower}{blank}*\}{blank}*, {printf("Estoy en terminals\n");addTerminal(g,stringify(yytext[0])); BEGIN DIST;}
<DIST>{upper}{blank}*,{blank}*\{ {printf("Estoy en dist: %c\n",yytext[0]);g->dist = yytext[0];BEGIN PRODUCTIONFROM;}
<PRODUCTIONFROM>{upper}{blank}*\-> {printf("from: %c\n",yytext[0]);p=newProduction(g);p->from=yytext[0]; BEGIN PRODUCTIONTO;}

<PRODUCTIONTO>{blank}* {BEGIN PRODUCTIONTO;}
<PRODUCTIONTO>{lower}+ {printf("to: %s <--productive\n",yytext);addWord(p,yytext);p->productive=true;BEGIN PRODUCTIONSEPARATOR;}
<PRODUCTIONTO>{letter}+ {printf("to: %s\n",yytext);addWord(p,yytext);BEGIN PRODUCTIONSEPARATOR;}
<PRODUCTIONTO>{lambda} {printf("to: %s\n",yytext);addWord(p,yytext);p->productive=true;BEGIN PRODUCTIONSEPARATOR;}

<PRODUCTIONSEPARATOR>{blank}*\|{blank}* {char from=p->from;p=newProduction(g);p->from=from;BEGIN PRODUCTIONTO;}
<PRODUCTIONSEPARATOR>{blank}*,{blank}* {BEGIN PRODUCTIONFROM;}
<PRODUCTIONSEPARATOR>{blank}*\}{blank}*\) {printf("Listo\n");processGrammar(g);}

. {printf("error:%s\n",yytext);newSyntaxError();}

%%

void newSyntaxError(){
	printf("Syntax error: Not well written grammar.\n");
	exit(1);
}

void processErrors(int err){
	if(err == NO_ERROR){
		return;
	}
	switch( err ) {
		case INVALID_DIST:
			printf("Error! El distinguido no es parte de los no terminales.\n");
			break;
		case INVALID_FROM:
			printf("Error! Al menos uno de los no terminales que producen no esta declarado.\n");
			break;
		case INVALID_SYMBOL:
			printf("Error! Al menos uno de los no simbolos (terminales o no terminales) producidos no esta declarado.\n");
			break;
		case DIST_NOT_USED:
			printf("Error! El no terminal distinguido no tiene produccion.\n");
			break;
		default :
			;
	}
	exit(1);
}

void processGrammar(Grammar g){
	processErrors(validateGrammar(g));
	/*printGrammar(g);
	g = removeUnreachableProductions(g);
	g = removeUnproductiveNodes(g);
	g->name = "Nueva Gramatica";
	printGrammar(g);*/
}

int main(void){
	yylex();
	return 0;
}
