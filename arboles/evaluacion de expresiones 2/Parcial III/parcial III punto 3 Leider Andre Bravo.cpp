#include <stdio.h>
#include <string.h>



int leerTexto(char texto[][100]){
	FILE *arch;
	arch=fopen("prueba.txt","rt");
	if (arch==NULL) {
		printf("\nNo se puede leer el archivo");
		return -1;
	}
	int cont=0;
	while (!feof(arch)) {
		fgets(texto[cont],80,arch);
	//	printf("\n %s",texto[cont]);   nota: presenta caracteres extraños durante la lectura
		cont++;
	}
	fclose(arch);
	return cont;//numero de renglones
}

bool esVocal(char x){
	x==97 || x==69 || x==73 || x==79 || x==85 || x==97 || x==101 || x==105 || x==111 || x==117;  //posiciones de las vocales en la tabla asci
}

bool esConsonante(char x){
	return ((x>64 && x<91)  || (x>96 && x<123)) && !esVocal(x);  //es una letra y no es una vocal
}

void numletras(char texto[][100],int renglones,int &vocales,int &consonantes){
	vocales=0;
	consonantes=0;
	int numVocales=0;
	for(int i=0;i<=renglones;i++)
		for(int j=0;j<strlen(texto[i]);j++){
			if(esVocal(texto[i][j]))
			    vocales++;
			if(esConsonante(texto[i][j]))
			    consonantes++;
		}
}



int main(void){
	char texto[100][100];
	int renglones;
	renglones=leerTexto(texto);
	int vocales,consonantes;
	numletras(texto,renglones,vocales,consonantes);
    printf("el texto es:\n\n");
    for(int i=0;i<=renglones;i++)
        puts(texto[i]);
    printf("\n\nnumero de vocales: %d \n numero de consonantes %d",vocales,consonantes);
	
	return 0;
}
