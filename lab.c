#include <stdio.h>
#include "lab.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

int main(void)
{
	int ntoken, vtoken;
	
	ntoken = yylex();
	// while(ntoken) {
	// 	printf("%d\n", ntoken);
	// 	ntoken = yylex();
	// }
	while(ntoken) {
		printf("%d\n", ntoken);
		printf(" Contiene %s\n", yytext);
		vtoken = yylex();
		while(vtoken==ESPACIO){
			vtoken = yylex();
		}
		switch (ntoken) {
		
		case ESPACIO:
			
		case IDENTIFICADOR:
			
			if(vtoken == ELSE || vtoken==RETURN || vtoken==FOR || vtoken==BREAK || vtoken==IDENTIFICADOR || vtoken==WHILE || vtoken==CONTINUE || vtoken==IF || vtoken==DEF || vtoken==IMPORT || vtoken==PASS || vtoken==PRINT || vtoken==INTEGER || vtoken==DECIMAL || vtoken==IMAGINARIO || vtoken==LONGINTEGER || vtoken==STRING){
				printf("Syntax error in line %d, but found %s\n", yylineno, yytext);
				printf("aca %d\n", vtoken);
				 
			}
			
			break;
		
		default:
			printf("Syntax error in line %d\n",yylineno);
		}
		ntoken = yylex();
	}

	return 0;
}


