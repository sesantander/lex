%{
#include "lab.h"
%}


integer [+-]?[0-9]+
decimal [0-9]*[0-9.][0-9]*([Ee][-+]?[0-9]+)?
imaginario ({integer}|{decimal})[jJ]  	
identificador [_a-zA-Z][_a-zA-Z0-9]*

%%
"and" return AND;
"else"  return ELSE;
"is"  return IS;
"return" return RETURN;
"for"  return FOR;
"break"  return BREAK;
"not"  return NOT;
"while" return WHILE;
"continue"  return CONTINUE;
"if"  return IF;
"or" return OR;
"def" return DEF;
"import"  return IMPORT;
"pass" return PASS;
"print" return PRINT;
"in" return IN;
"+" return SUMA;
"-" return RESTA;
"*" return MULT;
"**" return EXP;
"/" return DIV;
"//" return FDIV;
"%" return MOD;
"<<" return DESBIZQ;
">>" return DESBDER;
"&" return AND;
"|" return OR;
"^" return CIRCUN;
"~" return COMPLEBI;
"<" return LT;
">" return GT;
"<=" return LET;
">=" return GET;
"==" return IGUAL2;
"!=" return DIFERENTE;
"<>" return DIFERENTEOTRAVES;
"(" return	PARABRE;
")" return 	PARCIERRA;
"[" return	CORABRE;
"]" return	CORCIERRA;
"="  return	IGUAL;
";" return SEMICOLON;
","  return COMA;
":"  return COLON;
"."  return DOT;
">>=" return MAYORIZQ2IGUAL;
"<<=" return  MAYORDER2IGUAL; 
"+="  return AUMENTAVAR; 
"-="  return RESTAVAR; 
"*="  return MULTIPLICAVAR; 
"/="  return DIVIDEVAR; 
"**=" return EXPVAR;
"//=" return FDIVVAR; 
"&=" return  ANDVAR;
"|="  return ORVAR; 
"^="  return CIRCUNVAR; 
"%="  return MODVAR;
" "   return ESPACIO;
"#".* return COMMENT;
"False"  return FALSES; 
"True"  return TRUES;

["'][a-zA-Z0-9]*['"] return STRING;

{integer}   return INTEGER;

{decimal} return DECIMAL;

{identificador}    return IDENTIFICADOR;

{imaginario} return IMAGINARIO;

({integer})("L"|"l") return LONGINTEGER;



.		printf("Unexpected character\n");

%%

int yywrap(void)
{
	return 1;
}
