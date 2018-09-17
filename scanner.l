%{
#include <stdlib.h>
#include "y.tab.h"
#include "symbol.h"
extern void nextline();
extern int yylval;
%}

%%
"="     {return EQ;}
"!="    {return NE;}
"<"     {return LT;}
"<="    {return LE;}
">"     {return GT;}
">="    {return GE;}
"+"     {return PLUS;}
"-"     {return MINUS;}
"*"     {return MULT;}
"/"     {return DIVIDE;}
")"     {return RP;}
"("     {return LP;}
":="    {return ASSIGN;}
";"     {return SEMICOLON;}
"if"    {return IF;}
"then"  {return THEN;}
"else"  {return ELSE;}
"fi"    {return FI;}
"while" {return WHILE;}
"do"    {return DO;}
"od"    {return OD;}
"int"	{return INT;}
"float"	{return FLOAT;}
"char"	{return CHAR;}
"print" {return PRINT;}
[a-zA-Z_][0-9a-zA-Z_]* {yylval = symlook(yytext); return NAME;}
[0-9]+(\.[0-9]+)?  {yylval = atof(yytext); return NUMBER;}
\       {;}
\n      {nextline();}
\t      {;}
"//".*\n {nextline();}
.       {yyerror("illegal token");}
%%
#ifndef yywrap
yywrap() { return 1; }
int symlook(char* s){
    for(int id = 0; id < 30; id++){
	if(symtab[id].name && !strcmp(symtab[id].name,s)){
	    return id;
	}
	if(!symtab[id].name){
	    symtab[id].name = strdup(s);
	    return id;
	}
    }
    yyerror("Too many symblos");
    exit(1);
}
#endif
