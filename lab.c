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
		printf("--------------------------\n");
		printf("1 . El ntoken es %d\n", ntoken);
		printf(" Contiene %s\n", yytext);
		vtoken = yylex();
		printf("1 . El vtoken es %d\n", vtoken);
		while(vtoken==ESPACIO){
			vtoken = yylex();
		}
		printf("2 . El vtoken es %d\n", vtoken);
		switch (ntoken) {
		
		case ESPACIO:
			printf("entro un espacio\n");
			break;
		
		case IDENTIFICADOR:
			
			if(vtoken == ELSE || vtoken==RETURN || vtoken==FOR || vtoken==BREAK || vtoken==IDENTIFICADOR || vtoken==WHILE || vtoken==CONTINUE || vtoken==IF || vtoken==DEF || vtoken==IMPORT || vtoken==PASS || vtoken==PRINT || vtoken==INTEGER || vtoken==DECIMAL || vtoken==IMAGINARIO || vtoken==LONGINTEGER || vtoken==STRING){
				printf("Syntax error in line %d, but found %s\n", yylineno, yytext);
				printf("aca %d\n", vtoken);
				 
			}
			
			break;
		case IF:
            if(vtoken != IDENTIFICADOR && vtoken !=TRUES && vtoken !=FALSES && vtoken !=NOT && vtoken !=INTEGER && vtoken !=DECIMAL && vtoken !=IMAGINARIO && vtoken !=STRING && vtoken !=CORABRE && vtoken !=PARABRE){
                printf("Syntax error in line %d, but found %s\n", yylineno, yytext);
				printf("aca %d\n", vtoken);
            }
            break;
		case ELIF:
            if(vtoken != IDENTIFICADOR && vtoken !=TRUES && vtoken !=FALSES && vtoken !=NOT && vtoken !=INTEGER && vtoken !=DECIMAL && vtoken !=IMAGINARIO && vtoken !=STRING && vtoken !=CORABRE && vtoken !=PARABRE){
                printf("Syntax error in line %d, but found %s\n", yylineno, yytext);
				printf("aca %d\n", vtoken);
            }
            break;	
		case IMPORT:
            if(vtoken != IDENTIFICADOR){
                printf("Syntax error in line %d, but found %s\n", yylineno, yytext);
				printf("aca %d\n", vtoken);
            }
			break;
		case PASS:
			break;
		case IN:
			if(vtoken != IDENTIFICADOR){
                printf("Syntax error in line %d, but found %s\n", yylineno, yytext);
				printf("aca %d\n", vtoken);
            }
			break;
		case PRINT:
			if(vtoken != PARABRE && vtoken != PARABRE ){
                printf("Syntax error in line %d, but found %s\n", yylineno, yytext);
				printf("aca %d\n", vtoken);
            }
			break;
		}
		ntoken = vtoken;
		printf("2 . El ntoken es %d\n", ntoken);
	}

	return 0;
}