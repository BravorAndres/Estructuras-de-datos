#include <stdio.h>
#include "colas.h"

void invertirCola(ApTipoCola Cola){
	int valor;
    if(!colaVacia(Cola)){
    	valor=eliminarCola(Cola);
    	invertirCola(Cola);
    	insertarCola(Cola,valor);
	}
}

void destruirCola(ApTipoCola Cola){
	while(!colaVacia(Cola))
	    eliminarCola(Cola);
}

void copiaDeCola(ApTipoCola original,ApTipoCola destino){
	destruirCola(destino);
	TipoCola ColaAux;
	crearCola(&ColaAux);
	int aux;
	while(!colaVacia(original))
		insertarCola(&ColaAux,eliminarCola(original));    
			
	while(!colaVacia(&ColaAux)){
		aux=eliminarCola(&ColaAux);
		insertarCola(destino,aux);
		insertarCola(original,aux);
	}
}

bool colaOrdenada(ApTipoCola Cola){
	TipoCola aux;
	crearCola(&aux);
	copiaDeCola(Cola,&aux);
	if(colaVacia(&aux))
	    return true;
	int valor=eliminarCola(&aux);
	while(!colaVacia(&aux)){
		if(valor>consultarCola(&aux))
		    return false;
		valor=eliminarCola(&aux);	    
	}
	return true;
}

void ordenarCola(ApTipoCola Cola){
	if(colaVacia(Cola))
	    return;
	TipoCola ColaAux;
	crearCola(&ColaAux);
	int aux;
	for(;;){
    	aux=eliminarCola(Cola);
		while(!colaVacia(Cola)){
			if(consultarCola(Cola)>aux){
				insertarCola(&ColaAux,aux);
				aux=eliminarCola(Cola);
			}else{
				insertarCola(&ColaAux,eliminarCola(Cola));
			}
		}
		insertarCola(&ColaAux,aux);
		if(colaOrdenada(&ColaAux)){
			while(!colaVacia(&ColaAux))
			    insertarCola(Cola,eliminarCola(&ColaAux));
			return;
		}else{
			while(!colaVacia(&ColaAux))
			    insertarCola(Cola,eliminarCola(&ColaAux));
		}
	}
}

void llenarCola(ApTipoCola Cola){
	for(int i=48;i<58;i++)
		if(i%2==0)
		    insertarCola(Cola,i);
		else
		    insertarCola(Cola,i);
}

int nodosEnCola(ApTipoCola cola){
	TipoCola cola2;
	crearCola(&cola2);
	int numeroNodos=0;
	while(!colaVacia(cola)){
		insertarCola(&cola2,eliminarCola(cola));
		numeroNodos++;
	}
	while(!colaVacia(&cola2))
	    insertarCola(cola,eliminarCola(&cola2));
	return numeroNodos;    
}

int elementoDeCola(ApTipoCola cola,int elemento){
	int cont=0,nodo;
	elemento--;
	if(elemento>nodosEnCola(cola)||elemento<0){
		printf("\nfuera de limite");
		return NULL;
	}else{
		TipoCola cola2;
		crearCola(&cola2);
		while(!colaVacia(cola)){
			if(cont==elemento){
				nodo=eliminarCola(cola);
			//	insertarCola(&cola2,nodo);
			}else{
				insertarCola(&cola2,eliminarCola(cola));
			}   
			cont++;
		}
		while(!colaVacia(&cola2))
		    insertarCola(cola,eliminarCola(&cola2));
		return nodo;
	}
}

void ingresarElementoEnCola(ApTipoCola cola,int posicion,int nodo){
	TipoCola cola2;
	crearCola(&cola2);
	int cont=0;
	if(posicion>nodosEnCola(cola)||posicion<0){
		printf("\nfuera de limita");
		return;
	}else{
		while(!colaVacia(cola)){
		    if(cont==posicion){
	    		insertarCola(&cola2,nodo);
	    	}else{
	    		insertarCola(&cola2,eliminarCola(cola));
	    	}
	    	cont++;
	    }
	    while(!colaVacia(&cola2))
	        insertarCola(cola,eliminarCola(&cola2));
	}
}

int seleccionar(ApTipoCola cola,int saltar){
	TipoCola cola2,cola3;
	crearCola(&cola2);
	crearCola(&cola3);
	
	copiaDeCola(cola,&cola2);
	int cont=1;

	while(nodosEnCola(&cola2)!=1){
		while(!colaVacia(&cola2)){
			if(cont==saltar){
				eliminarCola(&cola2);
				cont=1;
			}else
			    insertarCola(&cola3,eliminarCola(&cola2));
			cont++;
		}
		while(!colaVacia(&cola3)){
			insertarCola(&cola2,eliminarCola(&cola3));
		}
	}
	return eliminarCola(&cola2);
}

int main(void){
	ApTipoCola Cola;
	Cola=(ApTipoCola)malloc(sizeof(TipoCola));
	TipoCola Cola2;
	crearCola(&Cola2);
	crearCola(Cola);
	llenarCola(Cola);
	imprimirCola(Cola);
	printf("buscador:%c",seleccionar(Cola,2));
	

}
