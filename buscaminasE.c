#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argv, char **args){
    char **nombreArchivo = &args[1];
    FILE *archivo;
	char caracter;
	archivo = fopen(&args[1],"r");
    int i=0,j=0;
    int renglones=0, columnas=0;
    char arregloDimensiones[2];
	if (archivo == NULL){
        printf("\nError al abrir el archivo. \n\n");
    }
    else{
        //Leer el primer renglon y guardar valores de renglon y columna 
         while((caracter = fgetc(archivo)) != '\n'){
            printf("%c \n",caracter);
            if (isdigit(caracter)){
                arregloDimensiones[i]=caracter;
                i+=1;
            }  
        }
        //volvemos a enteros los caracteres en char
        renglones=arregloDimensiones[0] - '0';
        columnas=arregloDimensiones[1]  - '0';
        int dimension= renglones * columnas;        
        printf("Las dimensiones son: [%d]x[%d] \n",renglones,columnas);
        //printf(" ->%d \n",renglones);
        //printf(" ->%d \n",columnas);

        int arregloMapa2[renglones][columnas];
        i=0;
        int j=0;
        printf("\nEl contenido es: \n");
        while((caracter = fgetc(archivo)) != EOF){
            printf("%c",caracter);
            if(caracter != '\n'){
                arregloMapa2[i][j]=caracter;
                j+=1;
                if(j==4){
                    i+=1;
                    j=0;
                }
            }            
	    }
        printf("\nEl contenido es: xd \n");
        for (i = 0; i < renglones; i++){
            for (j = 0; j < columnas; j++){
                if(arregloMapa2[i][j] == '.'){
                  arregloMapa2[i][j]=0 ;  
                }
                printf("%d ",arregloMapa2[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        printf("\n");
    }



}