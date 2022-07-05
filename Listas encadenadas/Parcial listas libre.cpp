/* Primer parcial de Estructuras de Datos

  1) Punto. Convertir de base 10 a cualqueir base entre 1 y 16.
  
  Utilizando el c�digo ac� proporcionado, debe escribir lo correspondiente a 
  la funci�n convertiraOtraBase, la cual recibe un n�mero entero que se 
  encuentra representado en base 10, y dado un n�mero entero que almacena cualquier 
  valor entre 1 y 16 que representa la bas a la cual se desea convertir, debe
  convertir el n�mero dado que est� en base 10 a la base indicada,almacenando 
  la respuesta en una lista d�gito por d�gito,  la cual debe retornar en el par�metro 
  correspondiente y debe quedar encadenada de tal manera que el d�gito m�s 
  significativo est� de primero en la lista, y que al escribirla con la funci�n 
  disponible (mostrar) salga como debe ser.
  Solo debe escribir la funci�n convertiraOtraBase, de la cual el prototipo ya
  se encuentra en este c�digo.
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
	// Escriba su c�digo a partir de ac�
	 
	int dig,resTemp,resto;

	
	for(resTemp = decimal%base;resTemp >0;resTemp = decimal%base){
		printf("%d\n",resTemp);
	}
	
	
	
	
	
}

int main(void){
	printf("jj\n");
	Datos *binario;
	int decimal, base;
	
//	binario = (Datos *)malloc(sizeof(Datos)); 
    printf("jj\n");
//	binario=NULL;
/*	printf("\nNumero a convertir : ");
	scanf("%d",&decimal);
	printf("\nBase a convertir : ");
	scanf("%d",&base);   */ 
    printf("jj\n");
	convertiraOtraBase(200, 5, &binario);
//	mostrar(binario);
}
