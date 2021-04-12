#include <stdio.h>
#include "lab.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

int main(void)
{
	int ntoken, vtoken;
	
	ntoken = yylex();
	
	while(ntoken) {
		printf("--------------------------\n");
		printf("El ntoken es %d y el texto es %s\n", ntoken,yytext);
		
		vtoken = yylex();
		
		while(vtoken==ESPACIO){
			vtoken = yylex();
		}
		

		switch (ntoken) {
		
		case ESPACIO:
			printf("entro un espacio\n");
			break;		
		case IDENTIFICADOR:			
			if(vtoken==DECIMAL){
				printf("Error unexpected %s\n",  yytext);
			}			
			break;
		case INTEGER:			
			if(vtoken == IDENTIFICADOR){
				printf("Error unexpected %s\n",  yytext);
							 
			}			
			break;
		case DECIMAL:			
			if(vtoken == IDENTIFICADOR || vtoken==DECIMAL || vtoken==IMAGINARIO ){
				printf("Error unexpected %s\n",  yytext);
							 
			}			
			break;
		case IMAGINARIO:			
			if(vtoken == IDENTIFICADOR || vtoken==DECIMAL || vtoken==IMAGINARIO ){
				printf("Error unexpected %s\n",  yytext);
							 
			}			
			break;
		case LONGINTEGER:			
			if(vtoken==IDENTIFICADOR){
				printf("Error unexpected %s\n",  yytext);
							 
			}			
			break;
		
	    case IGUAL:
			if(vtoken != IDENTIFICADOR && vtoken !=TRUES && vtoken !=FALSES && vtoken !=INTEGER && vtoken !=DECIMAL && vtoken !=IMAGINARIO && vtoken !=STRING && vtoken !=CORABRE && vtoken !=PARABRE){
				printf("Error unexpected %s\n",  yytext);
			}
			break;
		case UNDEFINED:
            printf("Unexpected Token\n");
            break;
        }
		
		ntoken = vtoken;
		
	}

	return 0;
}