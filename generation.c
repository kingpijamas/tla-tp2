#include "generation.h"

void makeASDR(Grammar g){
	system("rm -f ASDR*");
	writeC("\n#include <stdio.h>");
	writeC("\n#include <stdlib.h>");
	writeC("\n#include \"ASDR.h\"");
	writeC("\n#include \"utils.h\"");
	writeH("\n#ifndef ASDR_H_");
	writeH("\n#define ASDR_H_");
	writeH("\n#include <stdio.h>");
	writeH("\n#include <stdlib.h>");
	writeH("\n#include \"utils.h\"");
	writeC("\nint main(int argc, char ** argv){");
	writeC("\nif(argc != 2){");
	writeC("\nprintf(\"Cantidad de argumentos incorrecta.\\n\");");
	writeC("\nexit(1);");
	writeC("\n}");
	writeC("\nchar * ret = S((char * )argv[1], \"");
	writeCChar(g->dist);
	writeC("\");");
	writeC("\nif(strlen(ret) != 0){");
	writeC("\nprintf(\"SE ACEPTA LA CADENA \\n\");");
	writeC("\nprintf(\"");
	writeCChar(g->dist);
	writeC("%s\\n\", ret);");
	writeC("\nreturn 0;");
	writeC("\n}else{");
	writeC("\nprintf(\"NO SE ACEPTA LA CADENA\\n\");");
	writeC("\nreturn 1;");
	writeC("\n}");
	writeC("\n}");
	char * parsed = strdup("");
	Element e, e2;
	Production p, p2;
	FOR_EACH(e, g->productions){
		p=(Production)e->data;
			//printf("\n<<<%s>>>", parsed);
		if(!containsChar(parsed, p->from)){
			writeC("\n\nchar * ");
			writeCChar(p->from);
			writeC("(char * obj, char * prev){");
			/*writeH("\n\nboolean ");
			writeHChar(p->from);
			writeH("(char * obj, char * prev);");*/
			writeC("\nchar * current;");
			FOR_EACH(e2, g->productions){
				p2=(Production)e2->data;
				if(p2->from == p->from ){
					writeC("\ncurrent = expandFirstNonTerminal(prev, \"");
					writeC(p2->word);
					writeC("\");");
					writeC("\nif(goodDirection(current, obj)){");
					writeC("\nswitch (getFirstNonTerminal(current)) {");
					writeC("\nchar * ret;");
					writeC("\nchar * ret2;");
					int i = 0;
					while(g->nonTerminals[i] != '\0'){
						writeC("\ncase '");
						writeCChar(g->nonTerminals[i]);
						writeC("':");
						writeC("\nret = ");
						writeCChar(g->nonTerminals[i]);
						writeC("(obj, current);");
						writeC("\nif(strlen(ret) != 0){");
						writeC("\nret2 = strdup(\"->\");");
						writeC("\nret2 = concat(ret2, current);");
						writeC("\nret2 = concat(ret2, ret);");
						writeC("\nfree(ret);");
						writeC("\nfree(current);");
						writeC("\nreturn ret2;");
						writeC("\n}");
						writeC("\nbreak;");
						i++;
					}
					writeH("\n\nchar * ");
					writeHChar(p->from);
					writeH("(char * obj, char * prev);");
					writeC("\ncase '\\0':");
					writeC("\nret2 = strdup(\"->\");");
					writeC("\nret2 = concat(ret2, current);");
					writeC("\nfree(current);");
					writeC("\nreturn concat(ret2, current);");
					writeC("\ndefault:");
					writeC("\nbreak;");
					writeC("\n}");
					writeC("\n}");
				}
			}
			writeC("\nreturn \"\";");
			writeC("\n}");
			parsed = concatChar(parsed, p->from);
		}
	}
	writeC("\n\nboolean goodDirection(char * production, char * obj){");
	writeC("\nchar * aux = strdup(production);");
	writeC("\nchar * p1 = aux;");
	writeC("\nchar * p2 = obj;");
	writeC("\nwhile(true){");
	writeC("\nif(isupper(*p1)){");
	writeC("\nreturn true;");
	writeC("\n}");
	writeC("\nif(*p1 == *p2){");
	writeC("\nif(*p1 == '\\0'){");
	writeC("\nreturn true;");
	writeC("\n}else{");
	writeC("\np1++;");
	writeC("\np2++;");
	writeC("\n}");
	writeC("\n}else{");
	writeC("\nreturn false;");
	writeC("\n}");
	writeC("\n}");
	writeC("\n}");
	writeC("\n\nchar * expandFirstNonTerminal(char * prev, char * pattern){");
	writeC("\nint i = 0;");
	writeC("\nwhile(islower(prev[i])){");
	writeC("\ni++;");
	writeC("\n}");
	writeC("\nif(prev[i] == '\\0'){");
	writeC("\nreturn strdup(prev);");
	writeC("\n}");
	writeC("\nchar * aux = substring(prev, 0, i);");
	writeC("\naux = concat(aux, pattern);");
	writeC("\naux = concat(aux, substring(prev, i+1, strlen(prev)-i-1));");
	writeC("\nreturn aux;");
	writeC("\n}");
	writeC("\n\nchar getFirstNonTerminal(char * text){");
	writeC("\nchar * p = text;");
	writeC("\nwhile(islower(*p)){");
	writeC("\np++;");
	writeC("\n}");
	writeC("\nreturn *p;");
	writeC("\n}");
	writeH("\n\nboolean goodDirection(char * production, char * obj);");
	writeH("\n\nchar * expandFirstNonTerminal(char * prev, char * pattern);");
	writeH("\n\nchar getFirstNonTerminal(char * text);");
	writeH("\n#endif");

	system("chmod 777 ./ASDR.c");
	system("gcc -o ASDR ASDR.c utils.c");
}

int getTerminalCount(char * string){
	int i = 0;
	int count = 0;
	while(string[i] != 0){
		if(islower(string[i])){
			count++;
		}
		i++;
	}
	return count;
}

char * parseProductions(char from, char * word){
	return word;
}

char * getFirstTerminals(char * word){
	char * ret = strdup("");
	char * pointer = word;
	while(islower(*pointer)){
		ret = concatChar(ret, *pointer);
	}
	return ret;
}

void writeC(char * text){
	FILE *fp;
	fp=fopen("ASDR.c", "a");
	fprintf(fp, "%s", text);
	fclose(fp);
}

void writeCChar(char character){
	FILE *fp;
	fp=fopen("ASDR.c", "a");
	fprintf(fp, "%c", character);
	fclose(fp);
}

void writeH(char * text){
	FILE *fp;
	fp=fopen("ASDR.h", "a");
	fprintf(fp, "%s", text);
	fclose(fp);
}

void writeHChar(char character){
	FILE *fp;
	fp=fopen("ASDR.h", "a");
	fprintf(fp, "%c", character);
	fclose(fp);
}

