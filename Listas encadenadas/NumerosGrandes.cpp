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
		printf("%d",digito->valor);
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

void copiarNumero(Numero *original,Numero *nuevo){
	nuevo->cabeza=original->cabeza;
	nuevo->cola=original->cola;
}


/********************************************************************************************************************************
**************************************       funciones para leer un numero      *************************************************
*********************************************************************************************************************************/


bool esNumero(char caracteres[]){
	for(int i=0;i<strlen(caracteres);i++)
	   if(caracteres[i]<48 || caracteres[i]>57)
	        return false;
	return true;
}





 bool leerNumero(char numero[]){
    gets(numero);
    
    if(esNumero(numero))
        return true;
    else{
        printf("error ........................................  no es un numero\n");   
        return false;
    }
    
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


/**********************************************************************************************************************************
**************************************      funciones para multiplicar numeros       *********************************************
***********************************************************************************************************************************/

void multiplicarPorUnDigito(int dig,Digito *digito,Numero *resultado){
    int temp=0,res;
    for(;;digito=digito->ant){
    	res=digito->valor * dig + temp;
    
    	temp=insertarNumero(resultado,res);
    
    	if(digito->ant == NULL){
    		if(temp != 0)
    		    insertarPorCabeza(resultado,temp);
    	    return;
    	}
	}
	
}

Numero multiplicarDosNumeros(Digito *numero1,Numero *numero2){

	Numero *temp,*temp2,*temp3;
	
	temp = (Numero*)malloc(sizeof(Numero));
	crearNumero(temp);
	
	temp2 = (Numero*)malloc(sizeof(Numero));
	crearNumero(temp2);
	
	temp3 = (Numero*)malloc(sizeof(Numero));
	crearNumero(temp3);
	
	multiplicarPorUnDigito(numero1->valor,numero2->cola,temp);
	
	if(numero1->ant==NULL){
		return *temp;
	}
	
	int Cant0 = 1;
	
	for(numero1=numero1->ant; ;numero1=numero1->ant){
	    
		multiplicarPorUnDigito(numero1->valor,numero2->cola,temp2);
		for(int i=0; i<Cant0 ;i++)
		    insertarPorCola(temp2,0);
		Cant0++;
		
		sumar(temp,temp2,temp3);
		
		crearNumero(temp);
		copiarNumero(temp3,temp);
		
		crearNumero(temp2);
		crearNumero(temp3);
		
		if(numero1->ant==NULL){
			return *temp;
		}
	}
	    
}


Numero multiplicar(Numero *numero1,Numero *numero2){
	return multiplicarDosNumeros(numero1->cola,numero2);
}



void llenarPrueba(Numero *numero){
	for(int i=1;i<=9;i++)
	    insertarPorCola(numero,i);
}

int main(void){
    Numero numero1,numero2,resultado;
    
   crearNumero(&numero1);
   
   crearNumero(&numero2);
    
    
    crearNumero(&resultado);
    
    printf("digite lon numeros:\n\nnumero 1:");
    llenarNumero(&numero1);
    printf("\nnumero 2:");
    llenarNumero(&numero2);printf("\n\n");
    	
    for(int i=1;i!=0;){
    	
    	printf("los numeros son\n");
    	imprimirNumero(&numero1);printf("\n");
    	imprimirNumero(&numero2);
    	printf("\n\n\n");
    	printf("sumar los numeros................1\n");
    	printf("multiplicar los numeros..........2\n");
    	printf("editar los numeros...............3\n\n");
    	scanf("%d",&i);
    	if(i==1){
    		sumar(&numero1,&numero2,&resultado);
    		printf("la suma es :");
    		imprimirNumero(&resultado);
    		printf("\n\n");getche();
    		system("cls");
		}else if(i==2){
			resultado=multiplicar(&numero1,&numero2);
			printf("la multiplicacion es: ");
			imprimirNumero(&resultado);
			printf("\n\n");getche();
    		system("cls");
		}else if(i==3){
			crearNumero(&numero1);
			crearNumero(&numero2);
			printf("\n\ndigite losnumeros\nnumero1: ");
			llenarNumero(&numero1);
			printf("\nnumero2:  ");
			llenarNumero(&numero2);
			printf("\n\n");getche();
    		system("cls");
		}
    	
	}
    
	return 0;
}
