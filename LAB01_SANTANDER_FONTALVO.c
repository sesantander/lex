#include <stdio.h>
#include <string.h>
#include "lab.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

int inArray(char x[], char arr[100][100]);
int main(void)
{
	int ntoken, vtoken, idcont, errorcont;
	char ids[100][100];
	idcont= 0;
	ntoken = yylex();
	errorcont = 0;

		char str[55] = "";

	while(ntoken) {
		char tokentext[strlen(yytext)];
		
		

		strcpy(tokentext, yytext);
		vtoken = yylex();
		while(vtoken==ESPACIO){
			vtoken = yylex();
		}

		switch (ntoken) {
		
		case ENDOFLINE:
			break;
		
		case IDENTIFICADOR:
			
			if(vtoken==DECIMAL || strlen(str)!=0){
				errorcont=errorcont+1;
				printf("ERROR= %s%s ", str,tokentext);
				strcpy(str, "");
			}else{
				if (inArray(tokentext,ids)==0){
					idcont=idcont+1;
					strcpy(ids[idcont], tokentext);
					printf("id%d= %s ",idcont, tokentext);	
				}else{
					printf("id%d= %s ",inArray(tokentext,ids), tokentext);	
				}
			}		
			break;
		case INTEGER:			
			if(vtoken == IDENTIFICADOR){
				//str = tokentext;
				strcpy(str, tokentext);
				
			}else{
				printf("entero= %s ", tokentext);	
			}		
			break;
		case DECIMAL:			
			if(vtoken == IDENTIFICADOR || vtoken==DECIMAL || vtoken==IMAGINARIO ){
				errorcont=errorcont+1;
				printf("ERROR= %s ", tokentext);	
			}else{
				printf("decimal= %s ", tokentext);	
			}		
			break;
		case IMAGINARIO:			
			if(vtoken == IDENTIFICADOR || vtoken==DECIMAL || vtoken==IMAGINARIO ){
				errorcont=errorcont+1;
				printf("ERROR= %s ", tokentext);	
			}else{
				printf("imaginario= %s ", tokentext);	
			}			
			break;
		case LONGINTEGER:			
			if(vtoken==IDENTIFICADOR){
				errorcont=errorcont+1;
				printf("ERROR= %s ", tokentext);	
			}else{
				printf("longinteger= %s ", tokentext);	
			}			
			break;
	    case IGUAL:
			if(vtoken != IDENTIFICADOR && vtoken !=TRUES && vtoken !=FALSES && vtoken !=INTEGER && vtoken !=DECIMAL && vtoken !=IMAGINARIO && vtoken !=STRING && vtoken !=CORABRE && vtoken !=PARABRE){
				errorcont=errorcont+1;
				printf("ERROR= %s ", tokentext);	
			}else{
				printf("asign= %s ", tokentext);	
			}
			break;
		case STRING:	
				printf("string= %s ", tokentext);		
			break;
		case IF:
				printf("IF ");	
            break;
        case ELIF:
				printf("ELIF ");
            break;
        case IMPORT:
				printf("IMPORT ");	
            break;
		case DEF:
				printf("DEF ");	
            break;
        case PASS:
				printf("PASS ");	
            break;

        case PRINT:
				printf("PRINT ");	
            break;
		case RANGE:
				printf("RANGE ");	
            break;
        case RETURN:
				printf("RETURN ");	
            break;
        case AND:
				printf("AND ");	
            break;
		case OR:
				printf("OR ");	
            break;
		case IS:
				printf("IS ");	
            break;	
        case BREAK:
				printf("BREAK ");	
            break;
		case CONTINUE:
				printf("CONTINUE ");	
            break;	
        case FOR:
				printf("FOR ");	
            break;
		case NOT:
				printf("NOT ");	
            break;
		case WHILE:
				printf("WHILE ");	
            break;	
        case IN:
				printf("IN ");	
            break;
        case ELSE:
				printf("ELSE ");	
            break;
        case PARABRE:
				printf("parabre= %s ", tokentext);		
            break;
		case PARCIERRA:
				printf("parcierra= %s ", tokentext);	
            break;
        case CORABRE:
				printf("corabre= %s ", tokentext);	
            break;
		case CORCIERRA:
				printf("corcierra= %s ", tokentext);	
            break;
		case SUMA:
				printf("suma= %s ", tokentext);	
            break;
		case RESTA:
				printf("resta= %s ", tokentext);	
            break;
		case MULT:
				printf("mult= %s ", tokentext);	
            break;
		case EXP:
				printf("exp= %s ", tokentext);	
            break;
		case DIV:
				printf("div= %s ", tokentext);	
            break;
		case FDIV:
				printf("fdiv= %s ", tokentext);	
            break;
		case MOD:
				printf("mod= %s ", tokentext);	
            break;
		case DESBIZQ:
				printf("desbizq= %s ", tokentext);	
            break;
		case DESBDER:
				printf("desbder= %s ", tokentext);	
            break;
		case CIRCUN:
				printf("circun= %s ", tokentext);	
            break;
		case COMPLEBI:
				printf("complebi= %s ", tokentext);	
            break;
		case LT:
				printf("lt= %s ", tokentext);	
            break;
		case GT:
				printf("gt= %s ", tokentext);	
            break;
		case LET:
				printf("let= %s ", tokentext);	
            break;
		case GET:
				printf("get= %s ", tokentext);	
            break;
		case COMP:
				printf("comp= %s ", tokentext);	
            break;
		case DIFERENTE:
				printf("diferente= %s ", tokentext);	
            break;
		case DIFERENTE2:
				printf("diferente2= %s ", tokentext);	
            break;
		case COLON:
				printf("dospuntos= %s ", tokentext);	
            break;
		case SEMICOLON:
				printf("puntoycoma= %s ", tokentext);	
            break;
		case COMA:
				printf("coma= %s ", tokentext);	
            break;
		case DOT:
				printf("punto= %s ", tokentext);	
            break;
		case MAYORIZQ2IGUAL:
				printf("mayorizqigual= %s ", tokentext);	
            break;
		case MAYORDER2IGUAL:
				printf("mayorderigual= %s ", tokentext);	
            break;
		case AUMENTAVAR:
				printf("aumentavar= %s ", tokentext);	
            break;
		case RESTAVAR:
				printf("restavar= %s ", tokentext);	
            break;
		case MULTIPLICAVAR:
				printf("multiplicavar= %s ", tokentext);	
            break;
		case DIVIDEVAR:
				printf("dividevar= %s ", tokentext);	
            break;
		case EXPVAR:
				printf("expvar= %s ", tokentext);	
            break;
		case FDIVVAR:
				printf("fdivvar= %s ", tokentext);	
            break;
		case ANDVAR:
				printf("andvar= %s ", tokentext);	
            break;
		case ORVAR:
				printf("orvar= %s ", tokentext);	
            break;
		case CIRCUNVAR:
				printf("circunvar= %s ", tokentext);	
            break;
		case MODVAR:
				printf("modvar= %s ", tokentext);	
            break;
		case FALSES:
				printf("FALSE");	
            break;
		case TRUES:
				printf("TRUE");	
            break;
		case COMILLAS:
				printf("comillas= %s ", tokentext);	
            break;
		case COMILLA:
				printf("comilla= %s ", tokentext);	
            break;
		case UNDEFINED:
            printf("%s ", tokentext);
            break;

        }
		
		ntoken = vtoken;
	}
	printf("\n %d Identificadores \n",idcont);
	for (int i = 1; i < idcont+1; i++){
		printf("id%d= %s \n",i,ids[i]);	
	}	
	printf("%d Errores \n",errorcont);
	return 0;
}

int inArray(char x[], char arr[100][100]){
	for (size_t i = 0; i < 100; i++){
		if(strcmp(arr[i],x) == 0 ){
			return i;
		}
	}
	return 0;
}