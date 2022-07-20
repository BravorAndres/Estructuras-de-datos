#include <stdio.h>
#include <stdlib.h> 


typedef struct datos{
	float valor;
	struct datos *sgte;
} TipoPila, *ApTipoPila;

void show(ApTipoPila pila) {
	TipoPila *s;
	printf("\nLos valores en la Pila son : \n");
	for (s=pila;s!=NULL;s=s->sgte) {
		printf("%f.2\t",s->valor);
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

void push(ApTipoPila *pila, float numero){
	TipoPila *p;
	p=(ApTipoPila)malloc(sizeof(TipoPila));
	p->valor=numero;
	p->sgte=*pila;
	*pila=p;
}

float pop(ApTipoPila *pila) {
	TipoPila *p;
	float valor=NULL;
	if (!isempty(*pila)) {
		p=*pila;
		valor=p->valor;
		*pila=p->sgte;
		free(p);
	}
	return valor;
}

float top(ApTipoPila pila) {
	float valor=NULL;
	if (!isempty(pila))
		valor=pila->valor;
	return valor;
}

