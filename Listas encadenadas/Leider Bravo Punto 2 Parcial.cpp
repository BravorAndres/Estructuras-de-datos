#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct lista {
    int valor;
    struct lista *sgte;
}Lista;


void insertarCabeza(Lista **lista, int numero){
	Lista *p;
	p=(Lista *)malloc(sizeof(Lista));
	p->valor=numero;
	p->sgte=*lista;
	*lista=p;
}

void mostrar(Lista *fila) {
	Lista *s;
	
	for (s=fila;s!=NULL;s=s->sgte) {
		printf("%d ",s->valor);
	}
}

Lista *crearMatriz(int m,int n){
	Lista *matriz;
	
	matriz = (Lista *)malloc(sizeof(Lista)*m);
	for(int i=0;i<m;i++)
	    for(int j=0;j<n;j++){
	    	insertarCabeza(&matriz[i],0);
		}
	
	return matriz;
}  



void llenarMatriz(Lista **matriz,int m,int n){
	int val;
	Lista *p;
	
	for(int i=0;i<m;i++){
		val=i+1;
		for(p=matriz[i];p!=NULL;p=p->sgte){
			p->valor=val;
			val=val+m;
		}
	}
}

int  trazaMat(Lista **mat) {
	int sum=0;
	Lista *p;
	
	for(int i=0;i<m;i++){
		p=mat[i];
		for(int j=0;j<i;j++){
			p=p->sgte;
		}
		sum=sum+p->valor;    
	}
	
	return sum;
} 



int main(void){
	int m,n;
    printf("m:");
    scanf("%d",&m);
    printf("\nn: ");
    scanf("%d",&n);
    
    Lista **mat;
    
	mat = crearMatriz(m,n);
	
	llenarMatriz(mat,n,m);
	for(int i=0;i<m;i++){
		mostrar(mat[i]);
	}
	
	printf("\n\ntraza matriz = ";trazaMat(mat);

	llenarMatriz(mat,4,5);
	
	
	return 0;
}
