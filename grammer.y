%{
#include "symbol.h"
%}
%start ROOT

%token EQ NE LT LE GT GE
%token PLUS MINUS MULT DIVIDE 
%token RP LP ASSIGN SEMICOLON
%token IF THEN ELSE FI
%token WHILE DO OD
%token INT FLOAT CHAR
%token PRINT
%token NUMBER
%token NAME

%%

ROOT	: stmts {execute($1);}
	;

stmt	: designator ASSIGN exp {$$ = assignment($1, $3);}
	| PRINT exp {$$ = print($2);}
	| IF exp THEN stmts ELSE stmts FI {$$ = ifstmt($2, $4, $6);}
	| IF exp THEN stmts FI {$$ = ifstmt($2, $4, empty());}
	| WHILE exp DO stmts OD {$$ = whilestmt($2, $4);}
	;

stmts	: stmts SEMICOLON stmt {$$ = seq($1, $3);}
  	| stmt {$$ = $1;}
	;

exp	: E {$$ = $1;}
	| E EQ E {$$ = eq($1, $3);}
	| E NE E {$$ = ne($1, $3);}
	| E LT E {$$ = lt($1, $3);}
	| E LE E {$$ = le($1, $3);}
	| E GT E {$$ = gt($1, $3);}
	| E GE E {$$ = ge($1, $3);}
	;

E	: T {$$ = $1;}
	| E PLUS T {$$ = plus($1, $3);}
	| E MINUS T {$$ = minus($1, $3);}
	;

T	: F {$$ = $1;}
	| T MULT F {$$ = mult($1, $3);}
	| T DIVIDE F {$$ = divide($1, $3);}
	;

F	: PLUS F {$$ = $2;}
	| MINUS F {$$ = neg($2);}
	| LP exp RP {$$ = $2;}
	| NUMBER {$$ = number($1);}
	| designator {$$ = $1;}
	;

designator : NAME {$$ = name($1);}
	   ;

%%
int main()
{
    return yyparse();
}
int linenumber = 1;
yyerror(char *msg)
{
    printf("line %d: %s\n", linenumber, msg);
    exit(1);
}
nextline()
{
    linenumber++;
}
