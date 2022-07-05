#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


typedef struct datos{
	int valor;
	bool x;
	struct datos *sgte;
}Datos;


void nuevoDato(Datos **datos){
	Datos *p,*q;
	p=(Datos*)malloc(sizeof(Datos));
	printf("\ninserte el numero:");
	int x;
	scanf("%d",&x);
	p->valor=x;
	p->x=(x>30);
	p->sgte=NULL;
	if (*datos==NULL) {
		*datos=p;
	}
	else {
		q=*datos;
		while (q->sgte!=NULL) {
		   q=q->sgte;
	    }
	    q->sgte=p;
	}
}

void nuevoDato(Datos **datos,Datos *q){
	Datos *p;
	p=*datos;
	while(p->sgte != NULL)
	    p=p->sgte;
	p->sgte=q;
	    
}

void imprimirLista(Datos *datos){
	Datos *p;
	for(p=datos;p != NULL;p=p->sgte){
		printf("%d   %d\n",p->valor,p->x);
	}
}


void mostrar(Datos *lista) {
	Datos *s;
	printf("\nLos valores en la lista son : \n");
	for (s=lista;s!=NULL;s=s->sgte) {
		printf("%d\t",s->valor);
	//	getche();
	}
}

Datos* elementoMayor(Datos *datos){
	Datos *p,*q;
	for(p=datos,q=p;p!=NULL;p=p->sgte){
		if(p->valor > q->valor)
		    q=p;
	}
	return q;
}

int promedio(Datos *datos){
    int x=1;;
	for(Datos *p=datos;p!=NULL;p=p->sgte){
		x*=p->valor;
	}
	return x;
		
}


bool iguales(Datos *datos,Datos *q){
	Datos *p;
	return (p->valor==q->valor);
}


int repitencias(Datos *datos,Datos *p){
	int x;
	for(Datos *p=datos;p!=NULL;p=p->sgte){
		if(iguales(datos,p))
		    x++;
	}
	return x;
}




Datos *elementoRepetido(Datos *datos){
	
}


bool ordenado(Datos *datos){
	Datos *p=datos,*q;
	q=p->sgte;
	if(p==NULL)
	    return false;
    for(;q!=NULL;p=q,q=q->sgte){
    	if(p->valor  > q->valor)
    	    return false;
	}
	return true;
}



void ordenar(Datos **datos){
	Datos *p,*q,*w;
	for(p=*datos;p != NULL;p=p->sgte){
		for(q=p;q != NULL;q=q->sgte){
			if(p->valor < q->valor){
				w=p;
				p->sgte = q->sgte;
				q=p;
			}
		}
	}
}


int main(void){
    Datos *datos,*q;
    datos=(Datos*)malloc(sizeof(Datos));
    datos=NULL;
    q=(Datos*)malloc(sizeof(Datos));
    for(int i=0;i<4;i++){
    	nuevoDato(&datos);
    	printf("\n");
	}
	
	/*
	q->valor=23;
	q->x=false;
	q->sgte=NULL;
	nuevoDato(&datos,q);*/
	
	
	ordenar(&datos);
	mostrar(datos);
	

	
	
	
	
	return 0;
}
