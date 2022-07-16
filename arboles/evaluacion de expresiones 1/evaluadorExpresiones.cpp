#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


#include <math.h>
#include "datos.h"
#include "pilas.h"
#include "expresiones.h"

//estructura del arbol
typedef struct arbol{
	Datos datos;
	struct arbol *hizq=NULL,*hder=NULL;
}TipoArbol;


bool arbolVacio(TipoArbol *raiz){
	return raiz == NULL;
}


bool esHoja(TipoArbol *raiz){
	return raiz->hder==NULL && raiz->hizq==NULL;
}


void crearArbol(TipoArbol **raiz){
    *raiz=NULL;	
}

//imprimie un arbol en entrorden
void mostrarArbolEnt(TipoArbol *raiz){
	if (!arbolVacio(raiz)){
	    mostrarArbolEnt(raiz->hizq);
	    if (tipoDato(raiz->datos)==1)
	      printf("%.2f ",raiz->datos.valor);
	    else
	       printf("%c ",raiz->datos.operador);
	    mostrarArbolEnt(raiz->hder);
	}
}


//inserta los nodos en el arbol
void insertarNodos(char cadena[],int inicio,int fin,TipoArbol **raiz){
	TipoArbol *p;
	p=(TipoArbol*)malloc(sizeof(TipoArbol));
	if(p==NULL){
		printf("\nNo hay memoria");
		return;
	}
	
	int posOp=0;
	if(inicio<=fin){
		posOp=posOperador(cadena,inicio,fin);
		if(posOp!=-1){
			p->datos.operador=cadena[posOp];
			p->datos.valor=0;
			*raiz=p;
			insertarNodos(cadena,inicio+1,posOp-1,&(*raiz)->hizq);
            insertarNodos(cadena,posOp+1,fin-1,&(*raiz)->hder);			
		}else{
			p->datos.valor=obtenerValor(cadena,inicio,fin);
			p->datos.operador=' ';
			p->hder=p->hizq=NULL;
			*raiz=p;
		}
	}
}


//devuelve el resultado de la expresion almacenada en el arbol
float evaluar(TipoArbol *raiz){
	if(esHoja(raiz))
	    return raiz->datos.valor;
	else switch(raiz->datos.operador){
		case '+':
			return evaluar(raiz->hizq)+evaluar(raiz->hder);
		case'-':
			return evaluar(raiz->hizq)-evaluar(raiz->hder);
		case'*':
			return evaluar(raiz->hizq)*evaluar(raiz->hder);
		case'/':
			return evaluar(raiz->hizq)/evaluar(raiz->hder);
		case'^':
			return pow(evaluar(raiz->hizq),evaluar(raiz->hder));
		default:
			printf("\nerror de operadores");
			return 0;
	}
}



//programa principal
int main(void){
	char cadena[]="((12+24)+(3+4))*7\0";
	TipoArbol *arbol;
	crearArbol(&arbol);
	int band=1;
	do{
		printf("\n             CALCULADORA\n\n");
		printf("digite nueva expresion:\n");
		gets(cadena);
		eliminarCaracteres(cadena,' ');
		if(expresionValida(cadena)){
			insertarNodos(cadena,0,strlen(cadena),&arbol);
			printf("\n\n%s = %f\n\n",cadena,evaluar(arbol));
		}else{
			printf("puase");
			getche();
		}
	}while(band!=0) ;

	return 0;
}





