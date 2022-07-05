#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <conio.h>

typedef struct datos{
	char valor;
	struct datos *sgte;
}Datos;

void mostrar(Datos *lista) {
	Datos *s;
	printf("\nEl valor almacenado en la lista es : \n");
	for (s=lista;s!=NULL;s=s->sgte) {
		printf("%c ",s->valor);
	}
}

void insertarCola(Datos **lista, char numero){
	Datos *p,*q;
	p=(Datos *)malloc(sizeof(Datos));
	p->valor=numero;
	p->sgte=NULL;
	if (*lista==NULL) {
		*lista=p;
	}
	else {
		q=*lista;
		while (q->sgte!=NULL) {
		   q=q->sgte;
	    }
	    q->sgte=p;
	}
}

void insertarCabeza(Datos **lista, char numero){
	Datos *p;
	p=(Datos *)malloc(sizeof(Datos));
	p->valor=numero;
	p->sgte=*lista;
	*lista=p;
}

void convertiraOtraBase(int decimal, int base, Datos **binario){
	// Escriba su código a partir de acá
	 
	int dig,resTemp,resto;

	
	resTemp=decimal/base;
	dig=decimal-resTemp*base;
	printf("%d  %d  %d  ",resTemp,dig,decimal);
		
	
}



int main(void){

    printf("%d",200%5);getche();

	
	Datos *binario;
	printf("hola\n");
	convertiraOtraBase(40, 16, &binario);
	printf("hola\n");
	return 0;
}
