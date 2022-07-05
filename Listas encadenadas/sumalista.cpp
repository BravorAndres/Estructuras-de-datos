/*********************************************************************
    Programa que permite probar los diferentes operaciones de listas
    doblemente encadenadas que se utilizan en el curso de 
    Estructuras de Datos

      Universidad Nacional de Colombia sede Manizales
    	Eduardo Villegas J.
    	Profesor Asociado U.N.
********************************************************************/

/* Taller de aplicación: fecha 21 de abril antes de clase
Dados dos numeros muy grandes representados con listas doblemente encadenadas
donde cada dígito es un nodo.
Debe calcular y almacenar en una nueva lista la suma de los dos números
grandes.
Plus: hallar la multiplicación de dos números grandes.
Subirlo a la plataforma de Moodle !! (tarea)

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX  1000
#define VACIO  (-1)

/* 
Ejercicio:
Para subir al Moodle antes de la próxima clase.
Dadas dos listas con números enteros, hallar 
y retornar en una nueva lista la multiplicación entre ellas.
*/

typedef struct lista {
        char valor;
        struct lista *ante, *sgte;
} Lista;

typedef struct {
        Lista *cabeza, *cola;
} Lista2;


/********************************************************************
  Crea una lista doblemente encadenada vacía
********************************************************************/
void crearLista(Lista2 *lista){
	lista->cabeza=lista->cola=NULL;
}

/********************************************************************
  Saber si una lista doblemente encadenada está vacía
********************************************************************/
bool listaVacia(Lista2 *lista){
	return  (lista->cabeza==NULL && lista->cola==NULL);
}




/********************************************************************
  Inserta un valor en una lista por la cabeza de la lista
********************************************************************/
void insertarListaCab(Lista2 *lista, int elemento) {
   Lista *p;
   p=(Lista*)malloc(sizeof(Lista));
   if (p==NULL) {
   	   printf("\nNo hay memoria");
   	   return;
   }
   p->valor=elemento;
   p->sgte=p->ante=NULL;
   if (listaVacia(lista))
      lista->cabeza=lista->cola=p;
   else {
       p->sgte=lista->cabeza;
       lista->cabeza->ante=p;
       lista-> cabeza=p;
   }
}

/********************************************************************
  Inserta un valor en una lista por la cola de la lista
********************************************************************/
void insertarListaCol(Lista2 *lista, int elemento) {
   Lista *p;
   p=(Lista*)malloc(sizeof(Lista));
   if (p==NULL) {
   	   printf("\nNo hay memoria");
   	   return;
   }
   p->valor=elemento;
   p->sgte=p->ante=NULL;
   if (listaVacia(lista))
      lista->cabeza=lista->cola=p;
   else {
       p->ante=lista->cola;
       lista->cola->sgte=p;
       lista-> cola=p;
   }
}

/********************************************************************
  Busca un valor en una lista encadenada 
********************************************************************/
bool buscarLista(Lista2 *lista, int elemento) {
   Lista *p=lista->cabeza;
   while (p != NULL) {
       if (p->valor==elemento)
           return true;
       else
          p=p->sgte;
   }
   return false;
}


/********************************************************************
  Calcula el número de nodos de una lista
********************************************************************/
int contarLista(Lista2 lista) {
   Lista *p=lista.cabeza;
   int cont=0;
   while (p != NULL) {
       cont++;
       p=p->sgte;
   }
   return cont;
}


/********************************************************************
  Muestra el contenido de una lista desde la cabeza hasta la cola
********************************************************************/
void mostrarLista(Lista2 *lista) {
   Lista *p;
   printf("\nLa lista es :\n");
   for (p=lista->cabeza; p!=NULL; p=p->sgte)
       printf("%4d,",p->valor);
}

/********************************************************************
  Muestra el contenido de una lista recursivamente (ante)
********************************************************************/
void mostrarLista2an(Lista *lista)
{
   if (lista != NULL) {
       //printf("%4d,",lista->valor);
       mostrarLista2an(lista->sgte);
       printf("%4d,",lista->valor);
   }
}


void leer(Lista2 *numero) {
	char valor[25500];
	int cifra;
	crearLista(numero);
	printf("\nTeclee el numero : ");
	scanf("%s",valor);
	for (int x=0;x<strlen(valor);x++) {
		cifra=valor[x]-'0';
		insertarListaCol(numero, cifra);
	}
}

void sumar(Lista2 *lista1, Lista2 *lista2, Lista2 *respuesta) {
	Lista *p,*q;
	int valor,llevo,cifra;
	llevo=0;
	for  (p=lista1->cola,q=lista2->cola; p!=NULL && q!=NULL, p=p->ante,q=q->ante; ) {
		valor=p->valor+q->valor+llevo;
		if (valor>=10) {
			cifra = valor-10;
			llevo=1;
		}
		else {
		  cifra=valor;	
		  llevo=0;
	    }
		insertarListaCab(respuesta, cifra);
	}
	if (p!=NULL) {
		while (p!=NULL) {
			valor=p->valor+llevo;
			if (valor>=10) {
			   cifra = valor-10;
			   llevo=1;
		    }
		    else {
		      cifra=valor;	
		      llevo=0;
	        }
		    insertarListaCab(respuesta, cifra);
		    p=p->ante;
		}
	}
	if (q!=NULL) {
		while (q!=NULL) {
			valor=q->valor+llevo;
			if (valor>=10) {
			   cifra = valor-10;
			   llevo=1;
		    }
		    else {
		      cifra=valor;	
		      llevo=0;
	        }
		    insertarListaCab(respuesta, cifra);
		    q=q->ante;
		}
	}
	if (llevo>0)
	   insertarListaCab(respuesta, llevo);
}


void sumar2(Lista2 *lista1, Lista2 *lista2, Lista2 *respuesta) {
	Lista *p,*q;
	int valor,llevo,cifra,valor1,valor2;
	p=lista1->cola;
	q=lista2->cola;
	llevo=0;
	while (p!=NULL || q!=NULL) {
		if (p!=NULL)
		   valor1=p->valor;
		else
		   valor1=0;
		if (q!=NULL)
		   valor2=q->valor;
		else
		   valor2=0;
		valor=valor1+valor2+llevo;
		if (valor>=10) {
			cifra = valor-10;
			llevo=1;
		}
		else {
		  cifra=valor;	
		  llevo=0;
	    }
		insertarListaCab(respuesta, cifra);
		if (p!=NULL)
		    p=p->ante;
		if (q!=NULL)
		    q=q->ante;
	}
	if (llevo>0)
	   insertarListaCab(respuesta, llevo);
}

/********************************************************************
  Programa principal para el manejo de un árbol binario
********************************************************************/
int main(void) {
    int  valor, opcion, var;
    Lista2   lista, lista1, lista2;
    
    crearLista(&lista1);
    leer(&lista1);
    mostrarLista(&lista1);
    
    crearLista(&lista2);
    leer(&lista2);
    mostrarLista(&lista2);
    
    crearLista(&lista);
    sumar2(&lista1,&lista2,&lista);
    mostrarLista(&lista);
}
