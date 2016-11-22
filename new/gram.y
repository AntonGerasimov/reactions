%{
/*extern "C"
{
	int yyparse(void);
	int yylex(void);
	int yywrap()
	{
		return 1;
	}
}*/
int symbols[52];
int symbolVal(char symbol);
void updateSymbolVal(char symbol, int val);
#include <stdio.h>
#include <stdlib.h>
void yyerror (const char *str){fprintf(stderr, "ошибка: %s\n", str);}
%}
%union {int num; char id;}
%start reaction
%token exit_command
%token arrow
%token semicolon
%token <id> particle

%%

reaction	: particles arrow particles semicolon {printf("Reaction\n");}
		| exit_command semicolon	{exit(EXIT_SUCCESS);}
		| reaction particles arrow particles semicolon {printf("Reaction\n");}
		| reaction exit_command semicolon	{exit(EXIT_SUCCESS);}
particles	: particle {printf("ok: %c\n", symbolVal($1));}
		| particle particles
%%
int computeSymbolIndex(char token)
{
	int idx = -1;
	if (islower(token)){
		idx = token - 'a' + 26;
	} 	else if (isupper(token)){
		idx = token - 'A';
	}
	return idx;
}
int symbolVal(char symbol){
	int bucket = computeSymbolIndex(symbol);
	return symbols[bucket];
}
void updateSymbolVal(char symbol, int val){
	int bucket = computeSymbolIndex(symbol);
}
int main(void){
	int i;
	for (i=0; i<52; i++){
		symbols[i]=0;
	}
	return yyparse( );
}
