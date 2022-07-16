#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Nodos.h"
#include "Expresiones.h"

typedef struct arbol{
	Datos dato;
	struct arbol **hijos;
}TipoArbol;



int main(void){
	TipoArbol arbol;
	*(arbol.hijos)=(struct arbol*)malloc(sizeof(struct arbol)*5);
	
	
	return 0;
}
