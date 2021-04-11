#include <stdio.h>
#include "lab.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

int main(void)
{
	int ntoken, vtoken;
	int array[20];
	int z=0;
	ntoken = yylex();
	while(ntoken) {
		//printf("%d\n", ntoken);
		array[z] = ntoken;
		z=z+1;
		ntoken = yylex();
	}
	//    elif in print

	/* size of `array` in bytes */
	size_t size = sizeof(array);

	/* number of elements in `array` */
	size_t length = sizeof(array) / sizeof(array[0]); 
	
	
	// for (int j = 0; j < length; j++)
	// {
	// 	printf("Token %d\n",array[j]);
	// }
	
		int i=0;
	do
	{
			
				
			
			
				ntoken=array[i];
			if (ntoken != ESPACIO){
				printf("Token %d\n", ntoken);
				
				vtoken = array[i+1];
				while(vtoken==ESPACIO){
					i=i+1;
					vtoken = array[i+1];
				}
				
				
				

				//printf(" %d Vtoken\n", vtoken);
				
				
				switch (ntoken) {
				
				case ESPACIO:
					break;
				case IDENTIFICADOR:
					
					if(vtoken == ELSE || vtoken==RETURN || vtoken==FOR || vtoken==BREAK || vtoken==IDENTIFICADOR || vtoken==WHILE || vtoken==CONTINUE || vtoken==IF || vtoken==DEF || vtoken==IMPORT || vtoken==PASS || vtoken==PRINT || vtoken==INTEGER || vtoken==DECIMAL || vtoken==IMAGINARIO || vtoken==LONGINTEGER || vtoken==STRING){
						printf("Identificador Syntax error\n");
							
					}
					break;
				case IMPORT:
					if(vtoken != IDENTIFICADOR){
						printf("Import Syntax error\n");
					}
					break;
				case PASS:

				case IF:
					if(vtoken != IDENTIFICADOR && vtoken !=TRUES && vtoken !=FALSES && vtoken !=NOT && vtoken !=INTEGER && vtoken !=DECIMAL && vtoken !=IMAGINARIO && vtoken !=STRING && vtoken !=CORABRE && vtoken !=PARABRE){
						printf("IF Syntax error\n");
					}
					break;
				case ELIF:
					
					if(vtoken != IDENTIFICADOR && vtoken !=TRUES && vtoken !=FALSES && vtoken !=NOT && vtoken !=INTEGER && vtoken !=DECIMAL && vtoken !=IMAGINARIO && vtoken !=STRING && vtoken !=CORABRE && vtoken !=PARABRE){
						printf("ELIF Syntax error\n");
					}
					break;
			
				default:
					//printf("Syntax error in line %d\n",yylineno);
					printf(" ");
					break;   
				}
				

			}
			i=i+1;
			// if (array[i]<69)
			// {
			// 	break;
			// }
			
	} while (i<length);

	return 0;
}


