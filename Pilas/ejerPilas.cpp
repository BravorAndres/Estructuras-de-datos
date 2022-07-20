#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "pilas.h"

int sumaPila(ApTipoPila p,int *sum){
	int valor;
	if(isempty(p))
	    return 0;
	else{
		valor = pop(&p);
		*sum= valor+sumaPila(p,sum);
		push(&p,valor);	
	}
}

void invertirPila(ApTipoPila *pila){
	ApTipoPila p1,p2;
	p1=(ApTipoPila)malloc(sizeof(TipoPila));
	create(&p1);
	p2=(ApTipoPila)malloc(sizeof(TipoPila));
	create(&p2);
	while(!isempty(*pila))
	    push(&p1,pop(pila));
	while(!isempty(p1))
	    push(&p2,pop(&p1));
	while(!isempty(p2))
	    push(pila,pop(&p2));
}

void copiaDePila(ApTipoPila *original,ApTipoPila *copia){
	ApTipoPila aux;
	int valor;
	aux=(ApTipoPila)malloc(sizeof(TipoPila));
	create(&aux);
    while(!isempty(*original))
        push(&aux,pop(original));
    while(!isempty(aux)){
    	valor=pop(&aux);
    	push(original,valor);
    	push(copia,valor);
	}
}

int mayorPila(ApTipoPila pila){
	ApTipoPila pila2;
	pila2=(ApTipoPila)malloc(sizeof(TipoPila));
	create(&pila2);
	copiaDePila(&pila,&pila2);
	int valor;
	valor=pop(&pila2);
	while(!isempty(pila2)){
		if(valor<top(pila2))
		    valor=pop(&pila2);
		else
		    pop(&pila2);
	}
	return valor;
}

float promediaPila(ApTipoPila pila){
	int sum;
    
    
}


bool ordenada(int val,ApTipoPila p){
	if(isempty(p))
	    return true;
    if(val<top(p))
        return false;
    ordenada(pop(&p),p);
}

void llenar(ApTipoPila *pila){
	for(int i=0;i<20;i++)
		if(i%2==0)
		    push(pila,i);
		else
		    push(pila,i);
}

bool buscar(ApTipoPila *pila,int valor){
	if(isempty(*pila))
	    return false;
	ApTipoPila p1;
	create(&p1);
	bool encontrado=false;;
	while(!isempty(*pila)){
		if(top(*pila)==valor)
		    encontrado=true;
		push(&p1,pop(pila));
	}
	while(!isempty(p1))
	    push(pila,pop(&p1));
	return encontrado;
}


bool pilaPalindrome(ApTipoPila *pila){
	ApTipoPila p1,p2;
	p1=(ApTipoPila)malloc(sizeof(TipoPila));
	create(&p1);
	p2=(ApTipoPila)malloc(sizeof(TipoPila));
	create(&p2);
	copiaDePila(pila,&p1);
	copiaDePila(pila,&p2);
	invertirPila(&p2);
	while(!isempty(p1)){
		printf("\n%d ==%d",top(p1),top(p2));
	    if(pop(&p1)!=pop(&p2))
	        return false;
   }
	return true;
}



void eliminarRepitidos(ApTipoPila *pila){
	ApTipoPila p1;
	create(&p1);
	while(!isempty(*pila)){
		if(buscar(&p1,top(*pila)))
			pop(pila);
		else
		    push(&p1,pop(pila));
	}
	while(!isempty(p1))
	    push(pila,pop(&p1));
}




int contar(ApTipoPila *pila) {
	ApTipoPila aux;
	int valor,cont=0;
	create(&aux);
	while (!isempty(*pila)) {
		valor=pop(pila);
		cont++;
		push(&aux,valor);
	}
	while (!isempty(aux))
	    push(pila,pop(&aux));
	return cont;
}




void invertirMPila(ApTipoPila *pila,int posicion){
	int cont=0;
	posicion--;
	ApTipoPila pila2,pila3;
	create(&pila2);
	create(&pila3);
	while(cont<=posicion){
	    push(&pila2,pop(pila));
	    cont++;
	}
	while(!isempty(pila2))
	    push(&pila3,pop(&pila2));
	while(!isempty(pila3))
	    push(pila,pop(&pila3));
}

//***************************************  TDA     ***********
bool esOperador(char *cadena){
	if(strlen(cadena)==1){
		return cadena[0]=='+' || cadena[0]=='-' || cadena[0]=='*'||cadena[0]=='/';
	}else
	    return false;
}



int operar(int a1,int a2,char operador){
	switch(operador){
		case '+':
			return a2+a1;
			break;
		case '-':
			return a2-a1;
			break;
		case '*':
			return a1*a2;
			break;
		case '/':
			return a2/a1;
			break;
		default:
			printf("\n-----------    error  1");
			return NULL;
			break;
	}
}

int polaca(char expresion[]){
	ApTipoPila pila;
	create(&pila);
	char *tok;
	int a1,a2,res;
	
	for(tok=strtok(expresion,",");tok!=NULL;tok=strtok(NULL,",")){
	//	printf("");
	//	getche();
		if(esOperador(tok)){
			a1=pop(&pila);
			a2=pop(&pila);
			push(&pila,operar(a1,a2,tok[0]));
		}else{
			push(&pila,atoi(tok));
		}
		//show(pila);printf("\n\n");getche();
	}
	return pop(&pila);
}


int main(void){
	ApTipoPila pila,pila2;
	pila=(ApTipoPila)malloc(sizeof(TipoPila));
	create(&pila);
	pila2=(ApTipoPila)malloc(sizeof(TipoPila));
	create(&pila2);
	llenar(&pila);
	//show(pila);
	char cadena[]="80,4,/,4,*,16,-";
    printf("respuesta:%d",polaca(cadena));
	return 0;
}
