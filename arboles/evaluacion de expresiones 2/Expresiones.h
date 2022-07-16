

bool strcomp(char *str1,char *str2){
	if(strlen(str1)==strlen(str2)){
		for(int i=0;i<strlen(str1);i++)
		    if(str1[i]!=str2[i])
		        return false;
		return true;
	}else
	    return false;
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








