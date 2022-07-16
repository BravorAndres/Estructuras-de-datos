
typedef struct{
	float valor;
	char operador;
	char opCad[8];
	char tipo;//1:valor   2:operador simple    3:operador en cadena;
}Datos;

Datos nodo(char op){
	Datos aux;
	aux.valor=0;
	aux.operador=op;
	for(int i=0;i<8;i++)
	    aux.opCad[i]=' ';
	aux.tipo='2';
	return aux;
}

Datos nodo(char *op){
	Datos aux;
	aux.valor=0;
	aux.operador=' ';
	for(int i=0;i<strlen(op);i++)
	    aux.opCad[i]=op[i];
	aux.tipo='3';  
	return aux;
}

Datos nodo(float valor){
	Datos aux;
	aux.valor=0;
	aux.operador=' ';
	for(int i=0;i<8;i++)
	    aux.opCad[i]=' ';
	aux.tipo='1';
	return aux;
}



