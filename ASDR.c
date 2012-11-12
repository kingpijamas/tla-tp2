
#include <stdio.h>
#include <stdlib.h>
#include "ASDR.h"
#include "utils.h"
int main(int argc, char ** argv){
if(argc != 2){
printf("Cantidad de argumentos incorrecta.\n");
exit(1);
}
char * ret = S((char * )argv[1], "S");
if(strlen(ret) != 0){
printf("SE ACEPTA LA CADENA \n");
printf("S%s\n", ret);
return 0;
}else{
printf("NO SE ACEPTA LA CADENA\n");
return 1;
}
}

char * S(char * obj, char * prev){
char * current;
current = expandFirstNonTerminal(prev, "U");
if(goodDirection(current, obj)){
switch (getFirstNonTerminal(current)) {
char * ret;
char * ret2;
case 'S':
ret = S(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'U':
ret = U(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'V':
ret = V(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'T':
ret = T(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case '\0':
ret2 = strdup("->");
ret2 = concat(ret2, current);
free(current);
return concat(ret2, current);
default:
break;
}
}
current = expandFirstNonTerminal(prev, "V");
if(goodDirection(current, obj)){
switch (getFirstNonTerminal(current)) {
char * ret;
char * ret2;
case 'S':
ret = S(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'U':
ret = U(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'V':
ret = V(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'T':
ret = T(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case '\0':
ret2 = strdup("->");
ret2 = concat(ret2, current);
free(current);
return concat(ret2, current);
default:
break;
}
}
return "";
}

char * U(char * obj, char * prev){
char * current;
current = expandFirstNonTerminal(prev, "TaU");
if(goodDirection(current, obj)){
switch (getFirstNonTerminal(current)) {
char * ret;
char * ret2;
case 'S':
ret = S(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'U':
ret = U(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'V':
ret = V(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'T':
ret = T(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case '\0':
ret2 = strdup("->");
ret2 = concat(ret2, current);
free(current);
return concat(ret2, current);
default:
break;
}
}
current = expandFirstNonTerminal(prev, "TaT");
if(goodDirection(current, obj)){
switch (getFirstNonTerminal(current)) {
char * ret;
char * ret2;
case 'S':
ret = S(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'U':
ret = U(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'V':
ret = V(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'T':
ret = T(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case '\0':
ret2 = strdup("->");
ret2 = concat(ret2, current);
free(current);
return concat(ret2, current);
default:
break;
}
}
return "";
}

char * V(char * obj, char * prev){
char * current;
current = expandFirstNonTerminal(prev, "TbV");
if(goodDirection(current, obj)){
switch (getFirstNonTerminal(current)) {
char * ret;
char * ret2;
case 'S':
ret = S(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'U':
ret = U(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'V':
ret = V(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'T':
ret = T(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case '\0':
ret2 = strdup("->");
ret2 = concat(ret2, current);
free(current);
return concat(ret2, current);
default:
break;
}
}
current = expandFirstNonTerminal(prev, "TbT");
if(goodDirection(current, obj)){
switch (getFirstNonTerminal(current)) {
char * ret;
char * ret2;
case 'S':
ret = S(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'U':
ret = U(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'V':
ret = V(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'T':
ret = T(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case '\0':
ret2 = strdup("->");
ret2 = concat(ret2, current);
free(current);
return concat(ret2, current);
default:
break;
}
}
return "";
}

char * T(char * obj, char * prev){
char * current;
current = expandFirstNonTerminal(prev, "aTbT");
if(goodDirection(current, obj)){
switch (getFirstNonTerminal(current)) {
char * ret;
char * ret2;
case 'S':
ret = S(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'U':
ret = U(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'V':
ret = V(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'T':
ret = T(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case '\0':
ret2 = strdup("->");
ret2 = concat(ret2, current);
free(current);
return concat(ret2, current);
default:
break;
}
}
current = expandFirstNonTerminal(prev, "bTaT");
if(goodDirection(current, obj)){
switch (getFirstNonTerminal(current)) {
char * ret;
char * ret2;
case 'S':
ret = S(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'U':
ret = U(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'V':
ret = V(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'T':
ret = T(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case '\0':
ret2 = strdup("->");
ret2 = concat(ret2, current);
free(current);
return concat(ret2, current);
default:
break;
}
}
current = expandFirstNonTerminal(prev, "");
if(goodDirection(current, obj)){
switch (getFirstNonTerminal(current)) {
char * ret;
char * ret2;
case 'S':
ret = S(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'U':
ret = U(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'V':
ret = V(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case 'T':
ret = T(obj, current);
if(strlen(ret) != 0){
ret2 = strdup("->");
ret2 = concat(ret2, current);
ret2 = concat(ret2, ret);
free(ret);
free(current);
return ret2;
}
break;
case '\0':
ret2 = strdup("->");
ret2 = concat(ret2, current);
free(current);
return concat(ret2, current);
default:
break;
}
}
return "";
}

boolean goodDirection(char * production, char * obj){
char * aux = strdup(production);
char * p1 = aux;
char * p2 = obj;
while(true){
if(isupper(*p1)){
return true;
}
if(*p1 == *p2){
if(*p1 == '\0'){
return true;
}else{
p1++;
p2++;
}
}else{
return false;
}
}
}

char * expandFirstNonTerminal(char * prev, char * pattern){
int i = 0;
while(islower(prev[i])){
i++;
}
if(prev[i] == '\0'){
return strdup(prev);
}
char * aux = substring(prev, 0, i);
aux = concat(aux, pattern);
aux = concat(aux, substring(prev, i+1, strlen(prev)-i-1));
return aux;
}

char getFirstNonTerminal(char * text){
char * p = text;
while(islower(*p)){
p++;
}
return *p;
}