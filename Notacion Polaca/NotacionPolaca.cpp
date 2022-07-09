#include <stdio.h>
#include <string.h>
#include "pilasFloat.h"

bool esOperador(char *token){
	if(strlen(token)==1){
		return token[0]=='*'|| token[0]=='/'|| token[0]=='+'|| token[0]=='-'|| token[0]=='^';
	}
	return false;
}


void polaca(char cadena[]){
    char *token;
    ApTipoPila pila;
    create(&pila);
    float v1,v2,valor;
    for(token=strtok(cadena," ");token==NULL;token=strtok(NULL," ")){
    	if(esOperador(token)){
    		if(isempty(pila)){
    			printf("\nerror");
    			return;
			}
			if(token[0]=='+'){
				v1=pop(&pila);
				v2=pop(&pila);
				valor=v1+v2;
				push(&pila,valor);
			}else if(token[0]=='-'){
				v1=pop(&pila);
				v2=pop(&pila);
				valor=v1-v2;
				push(&pila,valor);
			}else if(token[0]=='*'){
				v1=pop(&pila);
				v2=pop(&pila);
				valor=v1*v2;
				push(&pila,valor);
			}else if(token[0]=='/'){
				v1=pop(&pila);
				v2=pop(&pila);
				valor=v1/v2;
				push(&pila,valor);
			}    
		}
	}
    
}

int main(void){
	
	return 0;
}
