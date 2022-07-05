#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct digito{
	int valor;
	struct digito *ant,*sgte;
}Digito;


typedef struct{
	Digito *cabeza,*cola;
}Numero;

void crearNumero(Numero *numero){
	numero->cabeza=numero->cola=NULL;
}


bool numeroVacio(Numero *numero){
	return (numero->cabeza == NULL && numero->cola == NULL);
}


void insertarPorCabeza(Numero *numero,int elemento){
	Digito *nuevoDig;
	nuevoDig = (Digito*)malloc(sizeof(Digito));
	
	nuevoDig->valor=elemento;
	nuevoDig->sgte=nuevoDig->ant=NULL;
	
	if(numeroVacio(numero)){
		numero->cabeza=numero->cola=nuevoDig;
	}else{
		nuevoDig->sgte=numero->cabeza;
		numero->cabeza->ant=nuevoDig;
		numero->cabeza=nuevoDig;
	}	
}


void insertarPorCola(Numero *numero,int elemento){
	Digito *nuevoDig;
	nuevoDig=(Digito*)malloc(sizeof(Digito));
	nuevoDig->sgte=nuevoDig->ant=NULL;
	nuevoDig->valor=elemento;
	if(numeroVacio(numero)){
		numero->cabeza=numero->cola=nuevoDig;
	}else{
		nuevoDig->ant=numero->cola;
		numero->cola->sgte=nuevoDig;
		numero->cola=nuevoDig;
	}
}


void imprimirDigitos(Digito *digito){
	if(digito != NULL){
		printf("%d ",digito->valor);
		imprimirDigitos(digito->sgte);
	//	printf("%d",digito->valor);
    }
	
}


void imprimirNumero(Numero *numero){
	if(numero !=NULL)
	    imprimirDigitos(numero->cabeza);
	else
	  ;//  printf("no hay digitos");
}



int contarNumero(Numero numero) {
   Digito *p=numero.cabeza;
   int cont=0;
   while (p != NULL) {
       cont++;
       p=p->sgte;
   }
   return cont;
}


void liberarMemoria(Digito *p){
	while(p->ant != NULL){
		p=p->ant;
		free(p->sgte);
	}
	free(p);
}

void liberarMemoria(Numero *p){
	liberarMemoria(p->cola);
}



/********************************************************************************************************************************
**************************************       funciones para leer un numero      *************************************************
*********************************************************************************************************************************/



 bool leerNumero(char numero[]){
    scanf("%s",numero);
    for(int i=0;i<strlen(numero);i++)
	   if(numero[i]<48 || numero[i]>57){
	   	    printf("\n\n-----------------------------------  error. No es un numero\n");
	        return false;
	    }
	return true;   
}

void llenarNumero(Numero *numero){
	char caracteres[250];
	for(;!leerNumero(caracteres););//obliga a digitar un numero	
    for(int i=0;i<strlen(caracteres);i++)
        insertarPorCola(numero,caracteres[i]-48);
}





/*************************************************************************************************************************
 *********************************      funciones para sumar dos numeros       *********************************************      
**************************************************************************************************************************/

int insertarNumero(Numero *resultado,int num){
	if(num/10 > 0){
		insertarPorCabeza(resultado,num%10);
		return num/10;
	}else{
		insertarPorCabeza(resultado,num);
		return 0;
   }    
}


/****************************************************************
    funcion que termina la operacion suma si uno de los 
	sumandos es mas grande que el otro
*****************************************************************/
void terminarSuma(Digito *digito,Numero *resultado,int temp){
	
	int res;
	for(;;){
		res=digito->valor+temp;
		temp=insertarNumero(resultado,res);
		
		if(digito->ant==NULL)
		    if(temp>0){
		        insertarPorCabeza(resultado,temp);
				return;
			}else
			    return;
		else
	        digito=digito->ant;
	   
	}
}


void sumarNumeros(Digito *numero1,Digito *numero2,Numero *resultado){
    int res,temp=0;
    
    for(;;){
    	res=numero1->valor + numero2->valor+temp;
    
    	temp=insertarNumero(resultado,res);
    	
    	if(numero1->ant==NULL){
    		if(numero2->ant != NULL){
    		    terminarSuma(numero2->ant,resultado,temp);
    		    return;
		   }else
			    return;
		}else if(numero2->ant==NULL){
			if(numero1->ant!=NULL){
			    terminarSuma(numero1->ant,resultado,temp);
			    return;
			}
		}else{
			numero1=numero1->ant;
			numero2=numero2->ant;
		}
		
	}
}

void sumar(Numero *numero1,Numero *numero2,Numero *resultado){
	sumarNumeros(numero1->cola,numero2->cola,resultado);
}



/*suma por acumulacion: el resultado que guardado en uno de los sumandos   */
void sumaPorAcumulacion(Numero *numero,Numero *resultado){
	Digito *numTemp,*resTemp;
	numTemp=numero->cola;
	resTemp=resultado->cola;
	int res,llevo=0;
	
	while(numTemp != NULL && resTemp != NULL){
		
		res=numTemp->valor+resTemp->valor+llevo;
	 // printf("%d+%d=%d  \n",resTemp->valor,numTemp->valor,res);
		if(res>=10){
		    llevo=1;
		    res=res-10;
		    resTemp->valor=res;
		}else{
		    llevo=0;
		    resTemp->valor=res;
	    }
		numTemp=numTemp->ant;
		resTemp=resTemp->ant;
	}
	
	while(numTemp !=NULL){
		res=numTemp->valor+llevo;
		if(res>=10){
			llevo=1;
			res=res-10;
			insertarPorCabeza(resultado,res);
		}else{
			llevo=0;
			insertarPorCabeza(resultado,res);
		}
		numTemp=numTemp->ant;
	}
	
	while(resTemp!=NULL){
		res=resTemp->valor+llevo;
		if(res>=10){
			llevo=1;
			res=res-10;
			resTemp->valor=res;
		}else{
			llevo=0;
			resTemp->valor=res;
		    return;
		}
		resTemp=resTemp->ant;
	}
	
	if(llevo>0)
	    insertarPorCabeza(resultado,llevo);	
}





/*********************************************************************************************

    funciones para multiplicar numeros un numero
    
**********************************************************************************************/


void multiplicarPorUnDigito(Digito *numero,int x,Numero *resultado){
	int res,llevo=0;
	while(numero != NULL){
		res=numero->valor*x + llevo;
		llevo=insertarNumero(resultado,res);
		numero=numero->ant;
	}
	if(llevo>0)
	    insertarPorCabeza(resultado,llevo);
}

void multiplicarNumeros(Numero *numero1,Numero *numero2,Numero *resultado){

	Numero *numTemp;
	numTemp=(Numero*)malloc(sizeof(Numero));
	crearNumero(numTemp);
	
	Digito *factor,*factTemp;
	factor=numero1->cola;
	
	insertarPorCabeza(resultado,0);
	int x=0;
	
	
	
	while(factor != NULL){
	    multiplicarPorUnDigito(numero2->cola,factor->valor,numTemp);
		for(int i=0;i<x;i++){
			insertarPorCola(numTemp,0);
		}
		x++;
		sumaPorAcumulacion(numTemp,resultado);
		liberarMemoria(numTemp);
		crearNumero(numTemp);
		factor=factor->ant;
	}
}


void multiplicar(Numero *p,Numero *r){
	multiplicarPorUnDigito(p->cola,9,r);
}


void prueba(Numero *p,int x){
	for(int i=0;i<x;i++)
	    insertarPorCabeza(p,i);
}



int main(void){
	
	Numero p,q,r;
	crearNumero(&p);
	crearNumero(&q);
	crearNumero(&r);
	
    int x=0;
    
    printf("digite los numero\n\n");
    printf("numero 1: ");
    llenarNumero(&p);
    printf("\nnumero 2: ");
    llenarNumero(&q);
    printf("\n\n");
    do{
    	system("cls");
    	printf("los numeros son:\n");
    	imprimirNumero(&p);
    	printf("\n\n");
    	imprimirNumero(&q);
    	printf("\n\nmultiplicar numeros...........................1\n");
    	printf("editar los numeros............................2\n");
    	
    	scanf("%d",&x);
    	if(x==1){
    		system("cls");
    		printf("los numeros son:\n");
    		imprimirNumero(&p);
    		printf("\n");
    		imprimirNumero(&q);
    		printf("\n\nel resultado es: ");
    		multiplicarNumeros(&p,&q,&r);
    		imprimirNumero(&r);printf("\n");
    		system("pause");
    		liberarMemoria(&r);
    		crearNumero(&r);
    		system("cls");
		}else if(x==2){
			liberarMemoria(&p);
			crearNumero(&p);
			liberarMemoria(&q);
			crearNumero(&q);
			system("cls");
			printf("numero 1: ");
			llenarNumero(&p);
			printf("\n\nnumero 2: ");
			llenarNumero(&q);
			system("pause");
			system("cls");
		}
	}while(x!=0);
	
	
}
