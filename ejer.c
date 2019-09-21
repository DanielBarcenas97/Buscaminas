#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



int main(int argv, char **args){
    char **nombreArchivo = &args[1];
	FILE *archivo;
	char caracter;
	archivo = fopen(*nombreArchivo,"r");
    int renglones=0;
    int columnas=0;
    char arregloMapa[2];
    
    
    int i=0;

	if (archivo == NULL){
        printf("\nError al abrir el archivo. \n\n");
    }
    else{
        //Leer el primer renglon y guardar valores de renglon y columna 
         while((caracter = fgetc(archivo)) != '\n'){
            //printf("%c \n",caracter);
            if (isdigit(caracter)){
                arregloMapa[i]=caracter;
                i+=1;
            }  
        }
        //printf("%s\n\n",arregloMapa);
        //volvemos a enteros los caracteres en char
        renglones=arregloMapa[0] - '0';
        columnas=arregloMapa[1]  - '0';
        int dimension= renglones * columnas;        
        printf("Las dimensiones son: [%d]x[%d] \n",renglones,columnas);
        //printf(" ->%d \n",renglones);
        //printf(" ->%d \n",columnas);

        int arregloMapa2[renglones][columnas];
        i=0;
        int j=0;
        //printf("\nEl contenido es: \n");
        while((caracter = fgetc(archivo)) != EOF){
            printf("%c",caracter);
            if(caracter != '\n'){
                arregloMapa2[i][j]=caracter;
                j+=1;
                if(j==renglones){
                    i+=1;
                    j=0;
                }
            }            
	    }
        /////Todo bien
        printf("\nEl contenido es: xd \n");
        for (i = 0; i < renglones; i++){
            for (j = 0; j < columnas; j++){
                if(arregloMapa2[i][j] == '.'){
                  arregloMapa2[i][j]=0 ;  
                }
                if(arregloMapa2[i][j] == '*'){
                  arregloMapa2[i][j]= '*' ;  
                }
                printf("%d ",arregloMapa2[i][j]);
            }
            printf("\n");
        }
        //Lugar donde estan las bombas

        for (i = 0; i < renglones; i++){
            for (j = 0; j < columnas; j++){
                printf("-->%d ",arregloMapa2[i][j]);
            
                if(i>0 && j>0){
                    if (arregloMapa2[i][j] == '*'){
                        arregloMapa2[i][j+1] += 1;
                        arregloMapa2[i][j-1] += 1;  
                        arregloMapa2[i+1][j] += 1;
                        arregloMapa2[i+1][j-1] += 1;  
                        arregloMapa2[i+1][j+1] += 1; 
                        arregloMapa2[i-1][j-1] += 1;
                        arregloMapa2[i-1][j+1] += 1; 
                        arregloMapa2[i-1][j] += 1; 
                    }
                }else if(i==0 && j==0){
                    if (arregloMapa2[i][j] == '*'){
                        arregloMapa2[i][j+1] = 1; 
                        arregloMapa2[i+1][j] = 1; 
                        arregloMapa2[i+1][j+1] = 1; 
                    }
                } else if(i==0 && j==columnas){
                    if (arregloMapa2[i][j] == '*'){
                        arregloMapa2[i][j-1] += 1; 
                        arregloMapa2[i+1][j] += 1; 
                        arregloMapa2[i+1][j-1] += 1; 
 
                    }
                } else if(i==renglones && j==columnas){
                    if (arregloMapa2[i][j] == '*'){
                        arregloMapa2[i][j-1] += 1;  
                        arregloMapa2[i-1][j-1] += 1;  
                        arregloMapa2[i-1][j] += 1; 
                    }
                } else  if(i==renglones && j==0){
                    if (arregloMapa2[i][j] == '*'){
                        arregloMapa2[i][j+1] += 1;  
                        arregloMapa2[i-1][j] += 1;  
                        arregloMapa2[i-1][j+1] += 1;  
                    }
                }else if(i==0 && j>0){
                    if (arregloMapa2[i][j] == '*'){
                        arregloMapa2[i][j-1] += 1; 
                        arregloMapa2[i][j+1] += 1;  
                        arregloMapa2[i+1][j] += 1;  
                        arregloMapa2[i+1][j+1] += 1;  
                        arregloMapa2[i+1][j-1] += 1;  
                    }
                } else  if(i>0 && j==0){
                    if (arregloMapa2[i][j] == '*'){
                        arregloMapa2[i][j+1] += 1;  
                        arregloMapa2[i-1][j] += 1; 
                        arregloMapa2[i+1][j] += 1; 
                        arregloMapa2[i+1][j+1] += 1;  
                        arregloMapa2[i-1][j+1] += 1;  
                    }
                }else  if(i==renglones && j>0){
                    if (arregloMapa2[i][j] == '*'){
                        arregloMapa2[i][j+1] += 1;  
                        arregloMapa2[i][j-1] += 1;  
                        arregloMapa2[i-1][j] += 1;
                        arregloMapa2[i-1][j+1] += 1;  
                        arregloMapa2[i-1][j-1] += 1;  
                    }
                } else if(i>0 && j==columnas){
                    if (arregloMapa2[i][j] == '*'){
                        arregloMapa2[i+1][j] += 1;  
                        arregloMapa2[i-1][j] += 1;  
                        arregloMapa2[i][j-1] += 1; 
                        arregloMapa2[i+1][j-1] += 1;  
                        arregloMapa2[i-1][j-1] += 1; 
                    }
                }
            }
            printf("\n");
        }

        printf("\n");
        printf("\n");
        printf("\nEl contenido es: \n");
        for (i = 0; i < renglones; i++){
            for (j = 0; j < columnas; j++){
                if(arregloMapa2[i][j] == '*'){
                    printf("%c ",arregloMapa2[i][j]);
                }else{
                    printf("%d ",arregloMapa2[i][j] );
                }
                
            }
            printf("\n");
        }
        printf("\n");

    }
    fclose(archivo);
	return 0;
}