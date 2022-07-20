/* Implementación de las funciones de la Pila con listas encadenadas
simples, bajo las siguientes operaciones:
-create : Crea una pila vacía 
-isempty : Determina si una pila esta vacia (sin elementos)
-push : Almacena un valor en la pila
-pop :  Retira un valor de la pila
-top : Consulta el valor que hay en la cima o tope de la pila
*/
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

typedef struct datos{
	int valor;
	struct datos *sgte;
} TipoPila, *ApTipoPila;

void show(ApTipoPila pila) {
	TipoPila *s;
	printf("\nLos valores en la Pila son : \n");
	for (s=pila;s!=NULL;s=s->sgte) {
		printf("%d\t",s->valor);
	}
}

void create(ApTipoPila *pila) {
	*pila=NULL;
}

bool isempty(ApTipoPila pila) {
	if (pila==NULL)
	   return true;
	else
	   return false;
}

void push(ApTipoPila *pila, int numero){
	TipoPila *p;
	p=(ApTipoPila)malloc(sizeof(TipoPila));
	p->valor=numero;
	p->sgte=*pila;
	*pila=p;
}

int pop(ApTipoPila *pila) {
	TipoPila *p;
	int valor=-1;
	if (!isempty(*pila)) {
		p=*pila;
		valor=p->valor;
		*pila=p->sgte;
		free(p);
	}
	return valor;
}

int top(ApTipoPila pila) {
	int valor=-1;
	if (!isempty(pila))
		valor=pila->valor;
	return valor;
}

