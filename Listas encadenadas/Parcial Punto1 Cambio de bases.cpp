/* Primer parcial de Estructuras de Datos

  1) Punto. Convertir de base 10 a cualquier base entre 1 y 16.
  
  Utilizando el código acá proporcionado, debe escribir lo correspondiente a 
  la función convertiraOtraBase, la cual recibe un número entero que se 
  encuentra representado en base 10, y dado un número entero que almacena cualquier 
  valor entre 1 y 16 que representa la bas a la cual se desea convertir, debe
  convertir el número dado que está en base 10 a la base indicada,almacenando 
  la respuesta en una lista dígito por dígito,  la cual debe retornar en el parámetro 
  correspondiente y debe quedar encadenada de tal manera que el dígito más 
  significativo esté de primero en la lista, y que al escribirla con la función 
  disponible (mostrar) salga como debe ser.
  Solo debe escribir la función convertiraOtraBase, de la cual el prototipo ya
  se encuentra en este código.
*/

#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

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
	char bases[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int res;
	if (base <=1) {
		printf("\nBase no valida");
		return;
	}
	*binario=NULL;
	while (decimal>0){
		res=decimal % base;
		insertarCabeza(binario,bases[res]);
		/* Otra forma sin el vector
		if (res>=0 && res<=9)
		  insertarCabeza(binario,48+res);
		else
		  insertarCabeza(binario,55+res);
		*/
		decimal=decimal/base;
	}
	// Acá termina lo que debe escribir
}

int main(void){
	Datos *binario;
	int decimal, base;
	binario=NULL;
	printf("\nNumero a convertir : ");
	scanf("%d",&decimal);
	printf("\nBase a convertir : ");
	scanf("%d",&base);
	convertiraOtraBase(decimal, base, &binario);
	mostrar(binario);
}
