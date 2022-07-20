#include <stdio.h>
#include "pilas.h"

/*EJERCICIOS:
1) Suma de los elementos de la pila  (recursivo) sin ciclos !!
2) Saber si una pila esta ordenada ascendentemente
3) Invertir el contenido de una pila (iterativo y recursivo)
4) Dada una pila ordenada, insertar un elemento para que siga ordenada
*/

void copia(ApTipoPila *pila, ApTipoPila *lacopia) {
	ApTipoPila aux;
	int valor;
	create(&aux);
	while (!isempty(*pila)) {
		valor=pop(pila);
		push(&aux,valor);
	}
	create(lacopia);
	while (!isempty(aux)) {
		valor=pop(&aux);
	    push(pila,valor);
	    push(lacopia,valor);
    }
}

void mostrar(ApTipoPila *pila) {
	ApTipoPila aux;
	create(&aux);
	printf("\nContenido de la pila : \n");
	while (!isempty(*pila)) {
		printf("\n\t%d",top(*pila));
		push(&aux,pop(pila));
	}
	while (!isempty(aux))
	    push(pila,pop(&aux));
}

void pasarArriba(ApTipoPila *pila, int dato) {
	ApTipoPila aux;
	bool encontro=false;
	int valor;
	if (isempty(*pila)) {
		return ;
	}
	create(&aux);
	while (!isempty(*pila) && !encontro) {
		valor=pop(pila);
		if (valor == dato)
		  encontro=true;
		else
		  push(&aux,valor);
	}
	while (!isempty(aux))
	    push(pila,pop(&aux));
	if (encontro)
	   push(pila,dato);
}

int mayor(ApTipoPila *pila) {
	ApTipoPila aux;
	int valor,may=0;
	if (isempty(*pila)) {
		return NULL;
	}
	may=top(*pila);
	create(&aux);
	while (!isempty(*pila)) {
		valor=pop(pila);
		if (valor > may)
		   may=valor;
		push(&aux,valor);
	}
	while (!isempty(aux))
	    push(pila,pop(&aux));
	return may;
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

void eliminar(ApTipoPila *pila, int dato) {
	ApTipoPila aux;
	int valor;
	bool encontro=false;
	create(&aux);
	while (!isempty(*pila) && !encontro) {
		valor=pop(pila);
		if (valor == dato) 
		   //encontro=true;
		   ;
		else
		   push(&aux,valor);
	}
	while (!isempty(aux))
	    push(pila,pop(&aux));
}

int suma(ApTipoPila *pila) {
	ApTipoPila aux;
	int valor,suma=0;
	create(&aux);
	while (!isempty(*pila)) {
		valor=pop(pila);
		suma+=valor;
		push(&aux,valor);
	}
	while (!isempty(aux))
	    push(pila,pop(&aux));
	return suma;
}


int main(void){
	ApTipoPila pila, lacopia;
	create(&pila);
	push(&pila,23);
	for (int x=1;x<=20;x++)
	   push(&pila,x);
	push(&pila,12);
	show(pila);
	mostrar(&pila);
	int num=contar(&pila);
	printf("\nLa cantidad de elementos es : %d",num);
	eliminar(&pila,12);
	mostrar(&pila);
	printf("\nEl mayor de la pila es : %d",mayor(&pila));
	pasarArriba(&pila,10);
	mostrar(&pila);
	printf("\nLa suma de los elementos es : %d",suma(&pila));
	copia(&pila,&lacopia);
	printf("\nLa copia es :\n");
	mostrar(&lacopia);
}



