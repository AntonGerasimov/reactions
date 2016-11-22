%{
#include <stdlib.h>
#include "y.tab.h"
%}
%%
"exit"		{return exit_command;}
"-->"		{return arrow;}
[;]		{return semicolon;}
[a-zA-Z][a-zA-Z]*	{return particle;}
[ \t\n]		;
.		{ECHO; yyerror ("unexpected character");}
%%
int yywrap (void) {return 1;}
