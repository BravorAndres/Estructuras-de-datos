

//compara dos cadena caracter a caracter
bool strcomp(char *str1,char *str2){
	if(strlen(str1)!=strlen(str2))
	    return false;
	else for(int i=0;i<strlen(str1);i++){
		if(str1[i]!=str2[i])
		    return false;
	}
	return true;
}

//elimina todas las apariciones de un caracter en una cadena
void eliminarCaracteres(char *cadena,char x){
	int cont=0;
	char aux[strlen(cadena)];
	for(int i=0;i<strlen(cadena);i++)
	    if(cadena[i]!=x){
	    	aux[cont]=cadena[i];
	    	cont++;
		}
	aux[cont]='\0';
	for(int i=0;i<strlen(aux);i++)
	    cadena[i]=aux[i];
	cadena[strlen(aux)]='\0';
}



bool esNumero(char x){
	return x>=48 || x<=57;
}



bool esOperador(char x){
	return x=='/' || x=='*' || x=='+' || x=='-' || x=='^';
}


//devuleve la prioridad de unsimbolo en la expresion matemetica
int prioridad_op(char x){
	switch (x){
		case '+':
			return 1;
			break;
		case '-':
			return 1;
			break;
		case '*':
			return 2;
			break;
		case '/':
			return 2;
			break;
		case '^':
			return 3;
			break;
		default:
			return -1;
			break;
	}
}

//devuleve la prioridad de operando en la expresion matemetica
int prioridad_op(char *op){
	char operandos[][10]={{"log\0"},{"ln\0"},{"raiz\0"},{"tan\0"},{"cot"},{"csc\0"},{"sec\0"},{"sen\0"},{"sin\0"},{"cos\0"}};
	if(strcomp(op,operandos[0]))
	    return 5;
	else if(strcomp(op,operandos[1]))
	    return 5;
	else if(strcomp(op,operandos[2]))
	    return 4;
	else if(strcomp(op,operandos[3]))
	    return 2;
	else if(strcomp(op,operandos[4]))
	    return 2;
	else if(strcomp(op,operandos[5]))
	    return 2;
	else if(strcomp(op,operandos[6]))
	    return 2;
	else if(strcomp(op,operandos[7]))
	    return 2;
	else if(strcomp(op,operandos[8]))
	    return 2;
	else if(strcomp(op,operandos[9]))
	    return 2;
}

//devuleve la posicion de un operador en la cadena dentro del limite dado.
//nota: ignora los numeros negativos
int posOperador(char *cadena,int inicio,int fin){
	int cont=0;
	for(int i=inicio;i<=fin;i++){
		if(cadena[i]=='('){
		    cont++;
		    
		}else if(cadena[i]==')')
		    cont--;
		else if(cont==1 && esOperador(cadena[i])){
		    if(cadena[i-1]!='(')//se es asi se asume que es un numero negativo
		        return i;
		}	
	}
	return -1;
}

//devuleve el valor entero de la cadena en el limite dado
int obtenerValor(char *cadena,int inicio,int fin){
	char num[10];
	int i,j;
	bool neg=false;
	
	for(i=inicio,j=0;i<=fin;i++,j++)
		num[j]=cadena[i];
	num[j]='\0';
	return atoi(num);
}


//devuleve verdadero si los parentesis de la exprresion estan dispuestos de manera correcta
bool balanceoAgrupacion(char *cadena){
	ApTipoPila pila;
	crearPila(&pila);
	Datos aux;
	for(int i=0;i<strlen(cadena);i++){
		if(cadena[i]=='(' ){
			aux.operador=cadena[i];
			insertarPila(&pila,aux);
		}else if(cadena[i]==')'){
				if(consultarPila(pila).operador=='(')
				    retirarPila(&pila);
				else
				    return false;
		}
	}
	return vaciaPila(pila);
}


//valida que la expresion este encerrada entre parentesis, si no lo esta corrige el error
void expresionEncerrada(char *cadena){
	int cont=0;
	bool encerrada=false;
	for(int i=0;i<strlen(cadena);i++){
		if(cadena[i]=='(')
		    cont++;
		else if(cadena[i]==')')
		    cont--;	
		if(cont==0 && i<strlen(cadena)-1)
		    encerrada=true;
	}
    if(encerrada){
    	char aux[strlen(cadena)+3];
    	int i;
    	aux[0]='(';
    	for(i=0;i<strlen(cadena);i++)
    	    aux[i+1]=cadena[i];
        aux[i+1]=')';
        aux[i+2]='\0';
    	for(i=0;i<strlen(aux);i++)
    	    cadena[i]=aux[i];
	}
}


//valida que una expresion matematica este dividida operaciones binarias
int esBinaria(char *cadena,int inicio,int fin){
	int contPa=0,contOp=0;
	for(int i=inicio;i<=fin;i++){
		if(cadena[i]=='(')
		    contPa++;
		else if(cadena[i]==')')
		    contPa--;
		if(contPa==1 && esOperador(cadena[i]))//es un simbolo
			if(esOperador(cadena[i-1])){
				if(cadena[i]!='-'){
					printf("\nerror de operadores");
					return -1;
				}
		    }else if(cadena[i-1]=='('){
		    	if(cadena[i]!='-'){
		    		printf("\nerror de operadores");
		    	    return -1;
		    	}
			}else
			    contOp++;	    
	}
	if(contOp==1)
	    return 1;
	else
	    return 0;
}


//valida que una expresion matematica y las expresiones dentro de los parentesis sean binarias
int expresionBinaria(char *cadena,int inicio,int fin){
	if(cadena[inicio]!='(')
		return 1;

	int posOp=0,binaria,izq,der;
	
	binaria=esBinaria(cadena,inicio,fin);
	if(binaria==1){
	    posOp=posOperador(cadena,inicio,fin);
	    izq=expresionBinaria(cadena,inicio+1,posOp-1);
	    der=expresionBinaria(cadena,posOp+1,fin-1);
	    if(izq<der)
	        return izq;
	    else
	        return der;
    }else
        return binaria;
}

bool expresionValida(char *cadena){
	eliminarCaracteres(cadena,' ');
	expresionEncerrada(cadena);
	int x;
	if(balanceoAgrupacion(cadena)){
		x=expresionBinaria(cadena,0,strlen(cadena)-1);
		if(x==0){
			printf("\nerror sintactico");
			return false;
		}else if(x==-1){
			return false;
		}else if(x==1)
		    return true;   
	}else
	    return false;
}



