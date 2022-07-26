#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


typedef struct Nodo{
	char nombre[25];
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





void insertarCola(ApTipoCola laCola,char *nombre){
	TipoNodo *p;
	p=(TipoNodo*)malloc(sizeof(TipoNodo));
	if(p==NULL){
		printf("\nNo hay memoria");
		return;
	}
	p->ant=NULL;
    
    strcpy(nombre,p->nombre);
	
	if(colaVacia(laCola)){
	   p->sgte=NULL;
	   laCola->cabeza=laCola->cola=p;  
	}else{
    	laCola->cola->ant=p;
    	p->sgte=laCola->cola;
    	laCola->cola=p;
    }
}


char *consultarCola(ApTipoCola laCola){
	if(colaVacia(laCola)){
		return NULL;
	}else{
		return laCola->cabeza->nombre;
	}
}

char *eliminarCola(ApTipoCola laCola){
	char *nombre;
	nombre=(char*)malloc(sizeof(char)*25);
	TipoNodo *p;
	
	if(colaVacia(laCola)){
		return NULL;
	}else{
		p=laCola->cabeza;
		strcpy(p->nombre,nombre);
		if(p->ant==NULL){
			laCola->cabeza=laCola->cola=NULL;
		}else{
			laCola->cabeza=p->ant;
			laCola->cabeza->sgte=NULL;
		}
		free(p);
		return nombre;
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
	    printf("%s\n",p->nombre);
	}
}
 
 
 
 
