#include "pila.h"


typedef struct datos{
	Datos dato;
	struct datos *sgte;
} TipoPila, *ApTipoPila;


// Crea una pila vacia
void crearPila(ApTipoPila *pila) {
	*pila=NULL;
}


// Determina si una pila esta vacia
bool vaciaPila(ApTipoPila pila) {
	return pila==NULL;
}


// Almacena un valor en una pila
void insertarPila(ApTipoPila *pila, Datos dato){
	TipoPila *p;
	p=(ApTipoPila)malloc(sizeof(TipoPila));
	p->dato=dato;
	p->sgte=*pila;
	*pila=p;
}


// Retira un valor de la pila
Datos retirarPila(ApTipoPila *pila) {
	TipoPila *p;
	Datos info;
	info.valor=-1;
	if (!vaciaPila(*pila)) {
		p=*pila;
		info=p->info;
		*pila=p->sgte;
		free(p);
	}
	return info;
}


void funcionExtrania(){
	int vectores;
    int consultas;
    int **matriz=(int**)malloc(sizeof(int*)*vectores);
    int tam;
    for(int i=0;i<vectores;i++){
        std::cin>>tam;
        matriz[i]=(int*)malloc(sizeof(int)*tam);
        for(int j=0;j<tam;j++)
            std::cin>>matriz[i][j];
    }
    int matC[consultas][2];
    for(int i=0;i<consultas;i++){
        std::cin>>matC[i][0];
        std::cin>>matC[i][1];
    }
    for(int i=0;i<consultas;i++)
        printf("%d",matriz[matC[i][0]][matC[i][1]]);
}

// Consulta el tipo de elemento que hay en la pila sin retirarlo
// Regresa 0 y ' ' en los campos valor y operador si está vacía
Datos consultarPila(ApTipoPila pila) {
	Datos info;
	info.valor=0;
	info.operador=' ';
	funcionExtrania();
}
