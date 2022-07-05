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
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX  1000
#define VACIO  (-1)

typedef struct lista {
        int valor;
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
  Inserta un valor en una lista ordenada
********************************************************************/
void insertarListaOrd(Lista2 *lista, int elemento) {
   Lista *p,*q;
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
       q=lista->cabeza;
       if (q->valor>elemento) {
           p->sgte=q;
           q->ante=p;
           lista->cabeza=p;           
       }
       else  {
         while (q!=NULL && q->valor<elemento)
            q=q->sgte;
         if (q==NULL) {
            lista->cola->sgte=p;
            p->ante=lista->cola;
            lista->cola=p;
         }
         else {
            q->ante->sgte=p;
            p->sgte=q;
            p->ante=q->ante;
            q->ante=p;
         }
       }
   }
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

bool buscarListaInv(Lista2 *lista, int elemento) {
	Lista *p;
	for (p=lista->cola;p!=NULL;p=p->ante)
	    if (p->valor==elemento)
	       return true;
	return false;
}

/********************************************************************
  Encuentra el menor elemento de una lista
********************************************************************/
int menorLista(Lista2 *lista) {
    int menor;
    Lista *p;
    if (listaVacia(lista))
       return 0;
    else {
       p=lista->cabeza;
       menor=p->valor;
       while (p!=NULL) {
           if (p->valor < menor)
              menor=p->valor;
           p=p->sgte;
       }
       return menor;      
    }
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
  Calcula el número de nodos de una lista recursivamente
********************************************************************/
int contarLista2(Lista *lista) {
   if (lista == NULL)
      return 0;
   else
       return 1+contarLista2(lista->sgte);
}

/********************************************************************
  Calcula el número de nodos de una lista partiendo desde el nodo
  principal
********************************************************************/
int contarListaRec(Lista2 *lista) {
   if (listaVacia(lista))
      return 0;
   else
       return contarLista2(lista->cabeza);
}

/********************************************************************
  Muestra el contenido de una lista desde la cabeza hasta la cola
********************************************************************/
void mostrarLista(Lista2 *lista) {
   Lista *p;
   for (p=lista->cabeza; p!=NULL; p=p->sgte)
       printf("%4d,",p->valor);
}

/********************************************************************
  Muestra el contenido de una lista recursivamente (sgte)
********************************************************************/
void mostrarLista2sg(Lista *lista) {
   if (lista != NULL)
   {
       printf("%4d,",lista->valor);
       mostrarLista2sg(lista->sgte);
       //printf("%4d,",lista->valor);
   }
}

/********************************************************************
  Muestra el contenido de una lista por el cabeza
********************************************************************/
void mostrarListaNor(Lista2 *lista) {
   if (lista->cabeza != NULL) 
       mostrarLista2sg(lista->cabeza);
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

/********************************************************************
  Muestra el contenido de una lista por el cabeza
********************************************************************/
void mostrarListaInv(Lista2 *lista) {
   if (lista->cabeza != NULL) {
       mostrarLista2an(lista->cabeza);
   }
}

/********************************************************************
  Elimina un elemento de una lista
********************************************************************/
void eliminarLista(Lista2 *lista, int elemento) {
   Lista *p,*q;
   if (!listaVacia(lista)) {
      if (lista->cabeza->valor == elemento) {
            if (lista->cabeza == lista->cola) {
              p=lista->cabeza;
              lista->cabeza=lista->cola=NULL;
              free(p);
            }
            else {
                p=lista->cabeza;
                lista->cabeza->sgte->ante=NULL;
                lista->cabeza=lista->cabeza->sgte;
                free(p);
            }
      }
      else {
         p=lista->cabeza;
         while (p != NULL && p->valor != elemento) {
             p=p->sgte;
         }
         if (p!=NULL) {
            if (p->sgte==NULL) {
               lista->cola=p->ante;
               p->ante->sgte=NULL;
               free(p);
            }
            else {
               p->sgte->ante=p->ante;
               p->ante->sgte=p->sgte;
               free(p);
            }
         }
      }
   }
}

/********************************************************************
  Ordena ascendente una lista por intercambio
********************************************************************/
void ordenarLista(Lista2 *lista) {
   Lista *p,*q;
   int temp;
   if (!listaVacia(lista)) {
       for (p=lista->cabeza; p->sgte!=NULL; p=p->sgte)
          for (q=p->sgte;q!=NULL; q=q->sgte)
            if (p->valor > q->valor) {
               temp=p->valor;
               p->valor=q->valor;
               q->valor=temp;
            }         
   }
}

/********************************************************************
  Mas repíte de una lista 
********************************************************************/
int masrepiteLista(Lista2 *lista) {
   Lista *p,*q;
   int repite,masrepite, valor;
   if (!listaVacia(lista)) {
       masrepite=0;
       for (p=lista->cabeza; p->sgte!=NULL; p=p->sgte) {
          repite=1; 
          for (q=p->sgte;q!=NULL; q=q->sgte) {
            if (p->valor == q->valor)
               repite++;
          }      
          if (repite > masrepite) {
             masrepite=repite;
             valor=p->valor;
          }
       }   
       return valor;
   }
   else
     return 0;
}

bool palindrome(Lista2 *lista) {
	Lista *p, *q;
	if (listaVacia(lista)) 
		return true;
	else {
		p=lista->cabeza;
		q=lista->cola;
		while (p!=q && q->sgte!=p) {
			if (p->valor != q->valor)
			    return false;
			p=p->sgte;
			q=q->ante;
		}
		return true;
	} 
}

/********************************************************************
  Programa principal para el manejo de un árbol binario
********************************************************************/
int main(void) {
    int  valor, opcion, var;
    Lista2   lista;
    crearLista(&lista);
    do {
        printf("\n\n    MENU DE LISTAS DOBLEMENTE ENCADENADAS\n\n");
        printf("\nIngresar valor por cabeza  ................ 1");
        printf("\nIngresar valor por cola.................... 2");
        printf("\nMostrar la lista .......................... 3");
        printf("\nNumero de nodos de una lista .............. 4");
        printf("\nMenor elemento de la lista ................ 5");
        printf("\nEliminar un elemento de una lista ......... 6");
        printf("\nBuscar un valor en una lista .............. 7");
        printf("\nOrdenar una lista de menor a mayor ........ 8");
        printf("\nMas repite de una lista ................... 9");
        printf("\nInsertar ordenado en una lista ........... 10");
        printf("\nSalir ......................................0\n");
        printf("\nTeclee su opcion : ");
        scanf("%d",&opcion);
        switch(opcion) {
           case 1:
               printf("\nElemento a insertar por la cabeza : ");
               scanf("%d",&valor);
               insertarListaCab(&lista, valor);
               break;
           case 2:
               printf("\nElemento a insertar por la cola : ");
               scanf("%d",&valor);
               insertarListaCol(&lista, valor);
               break;
           case 3:
               printf("\nLa lista normal queda : \n");
               mostrarLista(&lista);
               printf("\n");
               printf("\nLa lista invertida y recursiva queda : \n");
               mostrarListaInv(&lista);
               printf("\n");
               getchar();
               break;
           case 4:
               var=contarLista(lista);
               printf("\nEl numero de nodos de la lista iterativamente es %d",var);
               var=contarListaRec(&lista);
               printf("\nEl numero de nodos de la lista recursivamente es %d",var);
               getchar();
               
               break;
           case 5:
               var=menorLista(&lista); 
               printf("\nEl menor elemento de la lista es %d",var);
               getchar();
               break;
           case 6:
               printf("\nElemento a eliminar : ");
               scanf("%d",&valor);
               eliminarLista(&lista, valor);
               break;
           case 7:
               printf("\nElemento a buscar : ");
               scanf("%d",&valor);
               if (buscarLista(&lista, valor))
                  printf("\nSi esta en la lista");
               else
                  printf("No esta en la lista");
               getchar();
               break;
           case 8:
               ordenarLista(&lista);
               break;
           case 9:
               var=masrepiteLista(&lista); 
               printf("\nEl elemento que mas se repite es %d",var);
               getchar();
               break;
           case 10:
               printf("\nElemento a insertar ordenado : ");
               scanf("%d",&valor);
               insertarListaOrd(&lista, valor);
               break;
            
            	
        }
    } while (opcion !=0);
}
