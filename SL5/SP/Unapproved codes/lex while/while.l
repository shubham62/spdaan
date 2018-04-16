%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
int yylval;
%}
%option noyywrap

%%
while { return WHILE; }
[A-Za-z]([A-Za-z]|[0-9])* { return ID; }
[0-9]+ {yylval=atoi(yytext); return NUM;}
[ \t] ;
\n { yyterminate();}
. { return yytext[0];}
%%
