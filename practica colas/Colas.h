#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef struct Nodo{
	int valor;
	struct Nodo *sgte,*ant;
}TipoNodo;

typedef struct{
	TipoNodo *cabeza,*cola;
}TipoCola,*ApTipoCola;

bool colaVacia(ApTipoCola lacola){
	return lacola->cabeza==NULL && lacola->cola==NULL; 
}

void crearCola(ApTipoCola laCola){
	laCola->cabeza=laCola->cola=NULL;
}


void insertarCola(ApTipoCola laCola,int valor){
	TipoNodo *p;
	p=(TipoNodo*)malloc(sizeof(TipoNodo));
	if(p==NULL){
		printf("\nNo hay memoria");
		return;
	}
	p->ant=NULL;
	p->valor=valor;
	
	if(colaVacia(laCola)){
	   p->sgte=NULL;
	   laCola->cabeza=laCola->cola=p;  
	}else{
    	laCola->cola->ant=p;
    	p->sgte=laCola->cola;
    	laCola->cola=p;
    }
}


int consultarCola(ApTipoCola laCola){
	if(colaVacia(laCola)){
		return NULL;
	}else{
		return laCola->cabeza->valor;
	}
}

int eliminarCola(ApTipoCola laCola){
	int valor;
	TipoNodo *p;
	if(colaVacia(laCola)){
		return NULL;
	}else{
		p=laCola->cabeza;
		valor=p->valor;
		if(p->ant==NULL){
			laCola->cabeza=laCola->cola=NULL;
		}else{
			laCola->cabeza=p->ant;
			laCola->cabeza->sgte=NULL;
		}
		free(p);
		return valor;
	}
}

void ordenarBasico(ApTipoCola laCola){
	TipoNodo *p,*q;
	if(colaVacia(laCola))
		return;
	p=laCola->cabeza;
	int aux,i=0;
	while(p!=NULL){
		q=p->ant;
		while(q!=NULL){
		//	printf("\nvalor %d",q->valor);getche();
			if(p->valor>q->valor){
				aux=p->valor;
				p->valor=q->valor;
				q->valor=aux;
			}
			q=q->ant;
		}
		p=p->ant;
	}	
}

void imprimirCola(ApTipoCola laCola){
	TipoNodo *p;
	p=laCola->cabeza;
	if(colaVacia(laCola)){
		printf("\n   La cola esta vacia");
		return;
	}
	while(p!=NULL){
		printf("%c\t",p->valor);
		p=p->ant;
	}
}
 



