#include <stdio.h>
#include "colasChar.h"

void prueba(ApTipoCola cola,char cadena[100]){
	char *nombre;
	
	for(;;){
		printf("%s\n",nombre);
		insertarCola(cola,nombre);	
	}
}

int main(void){
	
	TipoCola cola;

	crearCola(&cola);
    
	prueba(&cola,"leider andres Bravo  Rodriguez\0");
	imprimirCola(&cola);
	
	return 0;
}

