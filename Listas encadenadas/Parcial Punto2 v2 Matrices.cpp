#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
   int valor;
   struct lista *sgte;
}Lista;


void insertar(Lista **cabeza) {
	Lista *p;
	p=(Lista *)malloc(sizeof(Lista));
	if (p==NULL) {
		printf("\nNo hay memoria");
		return ;
	}
	p->valor=0;
	p->sgte=*cabeza;
	*cabeza=p;
}

void mostrarLista(Lista *cabeza) {
	Lista *p;
	for (p=cabeza;p!=NULL;p=p->sgte)
	   printf("%4d",p->valor);
	printf("\n");
}

void mostrarVector(Lista **vector, int m, int n) {
	printf("\nLa estructura es :(%d,%d)\n",m,n);
	for (int x=0; x<m; x++) {
		mostrarLista(vector[x]);
	}
}

void crearVector(Lista *vector[], int m, int n) {
	for (int x=0;x<m;x++) {
		vector[x]=NULL;
		for (int y=0;y<n;y++) {
			insertar(&vector[x]);
		}
	}
}

int mirarXY(Lista *vector[], int m, int n, int x, int y) {
	Lista *p;
	p=vector[x];
	for (int i=1;i<=y;i++) {
		p=p->sgte;
		if (p==NULL) {
			printf("\nFuera de la matriz");
			return -1;
		}
	}
	return p->valor;
}

void ponerXY(Lista *vector[], int m, int n, int x, int y, int valor) {
	Lista *p;
	p=vector[x];
	for (int i=1;i<=y;i++) {
		p=p->sgte;
		if (p==NULL) {
			printf("\nFuera de la matriz");
			return;
		}
	}
	p->valor=valor;
}

void mostrarMatriz(Lista **vector, int m, int n) {
	printf("\nLa matriz es :(%d,%d)\n",m,n);
	for (int x=0; x<m; x++) {
		for (int y=0;y<n;y++)
		    printf("%4d",mirarXY(vector,  m,  n, x, y));
		printf("\n");
	}
}

int traza(Lista **vector, int m, int n) {
	int suma=0,tam;
	if (m<n)
	  tam=m;
	else
	   tam=n;
	for (int x=0;x<tam;x++)
	   suma+=mirarXY(vector,  m,  n, x, x);
	return suma;
}

int main(void) {
	int m=4;
	int n=5;
	Lista *vector[m];
	crearVector(vector,m,n);
	printf("\nTermine de crear");
	mostrarVector(vector,m,n);
	int cont=1;
	for (int y=0;y<n;y++)
	   for (int x=0;x<m;x++)
	      ponerXY(vector,m,n,x,y,cont++);
	mostrarVector(vector,m,n);
	mostrarMatriz(vector,m,n);
	printf("\nLa traza es : %d",traza(vector,m,n));
}
