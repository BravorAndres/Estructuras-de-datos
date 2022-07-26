#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct{
	char edad[3];
	char nombre[20];
	char apellido[20];
	float adcional;
	bool adicional2;
	
}Objeto;


typedef struct Nodo{
	Objeto persona;
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


void insertarCola(ApTipoCola laCola,Objeto persona){
	TipoNodo *p;
	p=(TipoNodo*)malloc(sizeof(TipoNodo));
	if(p==NULL){
		printf("\nNo hay memoria");
		return;
	}
	p->ant=NULL;
	p->persona=persona;
	
	if(colaVacia(laCola)){
	   p->sgte=NULL;
	   laCola->cabeza=laCola->cola=p;  
	}else{
    	laCola->cola->ant=p;
    	p->sgte=laCola->cola;
    	laCola->cola=p;
    }
}


Objeto consultarCola(ApTipoCola laCola){
	Objeto p;
	p.adicional2=false;
	if(colaVacia(laCola)){
		return p;
	}else{
		return laCola->cabeza->persona;
	}
}


Objeto eliminarCola(ApTipoCola laCola){
	Objeto persona,q;
	TipoNodo *p;
    q.adicional2=false;
	
	if(colaVacia(laCola)){
		return q;
	}else{
		p=laCola->cabeza;
		persona=p->persona;
		if(p->ant==NULL){
			laCola->cabeza=laCola->cola=NULL;
		}else{
			laCola->cabeza=p->ant;
			laCola->cabeza->sgte=NULL;
		}
		free(p);
		return persona;
	}
}



void imprimirPersona(Objeto persona){
	printf("\n\nedad: ");
	for(int i=0;i<strlen(persona.edad);printf("%c",persona.edad[i],i++));
	printf("\nnombre: ");
	for(int i=0;i<strlen(persona.nombre);printf("%c",persona.nombre[i],i++));
	printf("\napellido: ");
	for(int i=0;i<strlen(persona.apellido);printf("%c",persona.apellido[i],i++));
}


void imprimirCola(ApTipoCola laCola){
	TipoNodo *p;
	p=laCola->cabeza;
	if(colaVacia(laCola)){
		printf("\nCola vacia");
		return;
	}
	while(p!=NULL){
		imprimirPersona(p->persona);
	}
}



int main(void){
	
	return 0;
}

