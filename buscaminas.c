#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int leerArchivo(char *nombreArchivo){
    FILE *archivo;
	char caracter;
    char arregloDimensiones[2];
    int i =0;
    //printf("%s",nombreArchivo);
	archivo = fopen(nombreArchivo,"r");
    if (archivo == NULL){
        printf("\nError al abrir el archivo. \n\n");
    }
    else{
        //Leer el primer renglon y guardar valores de renglon y columna 
         while((caracter = fgetc(archivo)) != '\n'){
            //printf("%c \n",caracter);
            if (isdigit(caracter)){
                arregloDimensiones[i]=caracter - '0'; //Convertir el valor de Char a int
                i+=1;
            }  
        }
        
    }
    return *arregloDimensiones;
}



int main(int argv, char **args){
    //printf("%s\n", args[1]);
    char **nombreArchivo = &args[1];
    int i=0;
    int j=0;
    int renglon=0;
    int columna=0;
    int arregloDimensiones[2];
    *arregloDimensiones=leerArchivo(*nombreArchivo);
    renglon=arregloDimensiones[0];
    columna=(*arregloDimensiones + 1);
    //printf("%d",renglon);
    //int dimension = renglon * columnq;        
    printf("Las dimensiones son: [%d]x[%d] \n",renglon,columna);


}
