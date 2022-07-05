#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef struct datos{
    int valor;
    datos *sgte;
}Datos;


void nuevoDato(Datos **datos,int x){
	Datos *q,*p;
	
	
	
    p=(Datos*)malloc(sizeof(Datos));
    p->valor=x;
    p->sgte=NULL;
	if(*datos == NULL){
	    *datos=p;
	}else{
		q=*datos;
		while (!(q->sgte==NULL))
		    q=q->sgte;
		q->sgte=p;
	}  	    
}

void imprimir(Datos *datos){
	for(Datos *p=datos;p!=NULL;p=p->sgte){
		printf("%d\t",p->valor);
	}
}



//invertir recursivo
void invertir(Datos *datos){
    Datos *p;
    p=datos;
    printf("%d\t",p->valor);
    if(p->sgte ==  NULL){
       // printf("\n\n");
        return;
    }else
        invertir(p->sgte);
    printf("%d\t",p->valor);
    //printf("%d\t",p->valor);
   /* while(p->sgte!=NULL){
        printf("%d\t",p->valor);
        p=p->sgte;
    }  */
}



//mayor elemento recursivo
Datos *mayorElemento(Datos *datos,Datos *p){
	Datos *q=datos;
	if(q ==  NULL){
		return p;
	}else if(q->valor > p->valor)
	    p=q;
	return mayorElemento(q->sgte,p);
}


void prueba(Datos *p){
	Datos *q;
	q=p;
	printf("%d\n\n",q->valor);
	free(p);
	printf("%d",q->valor);
}



int main(void){
	Datos *datos;
	datos = (Datos*)malloc(sizeof(Datos));
	datos=NULL;
	
	
	//-------------Llenar datos ---------------
	for(int i=0;i<20;i++){
		if((i%2)==0)
		    nuevoDato(&datos,i*9);
		else
		    nuevoDato(&datos,2*i-i);   
		//nuevoDato(&datos,i);
	}
	
	prueba(datos->sgte->sgte);
	
	return 0;
}
