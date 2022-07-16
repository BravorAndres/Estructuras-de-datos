#include <stdio.h>
#include <stdlib.h>



typedef struct arbol{
	float valor;
	struct arbol *hizq,*hder,*hmed;
}TipoArbol;

void crearArbol(TipoArbol *arbol){
	arbol->hizq=arbol->hmed=arbol->hder=NULL;
}

bool arbolVacio(TipoArbol *raiz){
	return raiz==NULL;
}

bool esHoja(TipoArbol *arbol){
	return arbol->hizq==NULL && arbol->hmed==NULL && arbol->hder==NULL;
}

void llenarArbol(TipoArbol **raiz,float nodo){
	TipoArbol *p;
	p=(TipoArbol *)malloc(sizeof(TipoArbol));
	if(p==NULL){
		printf("\nNo hay memoria");
		return;
	}
	if(arbolVacio(*raiz)){
		crearArbol(p);
		p->valor=nodo;
		*raiz=p;
	}else{
		if((*raiz)->valor==nodo)
		    llenarArbol(&(*raiz)->hmed,nodo);
		else if(nodo<(*raiz)->valor)
		    llenarArbol(&(*raiz)->hizq,nodo);
		else if(nodo>(*raiz)->valor)
		    llenarArbol(&(*raiz)->hder,nodo);  	    
    }
}

float mayor(TipoArbol *raiz){
	if(esHoja(raiz))
	    return raiz->valor;
	else if(raiz->hder!=NULL)
	    return mayor(raiz->hder);//los numeros grandes solo se almacenan en el hijo derecho
	else 
	    return raiz->valor;      //en el hijo medio no tiene sentido consultar ya que es igual al nodo actual
}

void llenarArbolPrueba(TipoArbol *raiz){
	for(int i=0;i<20;i++){
		if(i%2==0){
		    llenarArbol(&raiz,i*2-4);
		  //  printf("%d \t",i*2-4);
		}else{
		    llenarArbol(&raiz,i*i-2*i);
		 //   printf("%d \t",i*i-2*i);
		}
	}
}
     


int main(void){
	TipoArbol *arbol;
	arbol=(TipoArbol *)malloc(sizeof(TipoArbol));
	if(arbol==NULL){
		printf("\nNo hay memoria");
		return 0;
	}
	crearArbol(arbol);
	llenarArbolPrueba(arbol);
	printf("mayor Almacenado: %.2f",mayor(arbol));
	
	
	return 0;
}
