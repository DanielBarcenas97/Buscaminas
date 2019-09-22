#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int **memoriaMatriz (int n,int m) {
	int i;
	int **mat;
	
	mat= (int **) calloc (n,sizeof (int *));
	for (i= 0; i < n; i++)
		mat[i]= (int *) calloc (m,sizeof (int));
	return mat;
}

void imprimeMatriz (int **arregloMapa2, int n, int m) {
	int i,j;
	//printf("Dentro \n");
	for (i= 0; i < n; i++) {
		for (j= 0; j < m; j++){
            if(arregloMapa2[i][j] == '*'){
                    printf("%c ",arregloMapa2[i][j]);
                }else{
                    printf("%d ",arregloMapa2[i][j] );
                }
        }
		printf ("\n");
	}
}

void Check(int **arregloMapa2, int i, int j){
    if(arregloMapa2[i][j]  == '*' ){
        arregloMapa2[i][j]  = '*';
    }else{
        arregloMapa2[i][j] += 1;
    }
}
void bombasActivas2(int **arregloMapa2, int renglones, int columnas) {
	int i,j;
    int d;
    d=renglones*columnas;
    printf("%d \n",d );
	for (i = 0; i < renglones; i++){
            for (j = 0; j < columnas; j++){
                //printf("-->%d ",arregloMapa2[i][j]);   <-----------------
                if(i>0 && j>0){  //Centro 
                    if (arregloMapa2[i][j] == '*'){
                        Check(arregloMapa2,i,j+1);
                        Check(arregloMapa2,i,j-1);
                        Check(arregloMapa2,i+1,j);
                        Check(arregloMapa2,i+1,j-1);
                        Check(arregloMapa2,i+1,j+1);
                        Check(arregloMapa2,i-1,j-1);
                        Check(arregloMapa2,i-1,j+1);
                        Check(arregloMapa2,i-1,j);
                    }
                }else if(i==0 && j==0 && d!=1){  //Coordenanda 0,0
                    if (arregloMapa2[i][j] == '*'){
                        Check(arregloMapa2,i,j+1);
                        Check(arregloMapa2,i+1,j);
                        Check(arregloMapa2,i+1,j+1);
                    }
                } else if(i==0 && j==columnas ){ // superior derecha
                    if (arregloMapa2[i][j] == '*'){
                        Check(arregloMapa2,i,j-1);
                        Check(arregloMapa2,i+1,j);
                        Check(arregloMapa2,i+1,j-1); 
 
                    }
                } else if(i==renglones && j==columnas ){ //inferior derecha
                    printf("hi2");
                    if (arregloMapa2[i][j] == '*'){
                        Check(arregloMapa2,i,j-1);
                        Check(arregloMapa2,i-1,j-1);
                        Check(arregloMapa2,i-1,j);
                    }
                } else  if(i==renglones && j==0 ){ //infeior izquierda
                    printf("hi");
                    if (arregloMapa2[i][j] == '*'){
                        Check(arregloMapa2,i,j+1);
                        Check(arregloMapa2,i-1,j);
                        Check(arregloMapa2,i-1,j+1);
                    }
                }else if(i==0 && j>0 ){
                    printf("hi3");
                    if (arregloMapa2[i][j] == '*'){
                        Check(arregloMapa2,i,j-1);
                        Check(arregloMapa2,i,j+1);
                        Check(arregloMapa2,i+1,j); 
                        Check(arregloMapa2,i+1,j+1); 
                        Check(arregloMapa2,i+1,j-1);
                    }
                } else  if(i>0 && j==0){
                    if (arregloMapa2[i][j] == '*'){
                        Check(arregloMapa2,i,j+1);
                        Check(arregloMapa2,i-1,j);
                        Check(arregloMapa2,i+1,j);
                        Check(arregloMapa2,i+1,j+1);
                        Check(arregloMapa2,i-1,j+1);
                    }
                }else  if(i==renglones && j>0){
                    if (arregloMapa2[i][j] == '*'){
                        printf("hola");
                        Check(arregloMapa2,i,j+1);
                        Check(arregloMapa2,i,j-1);
                        Check(arregloMapa2,i-1,j);
                        Check(arregloMapa2,i-1,j+1);
                        Check(arregloMapa2,i-1,j-1);
                    }
                } else if(i>0 && j==columnas){
                    if (arregloMapa2[i][j] == '*'){
                        Check(arregloMapa2,i+1,j);
                        Check(arregloMapa2,i-1,j);
                        Check(arregloMapa2,i,j-1);
                        Check(arregloMapa2,i+1,j-1);
                        Check(arregloMapa2,i-1,j-1);
                    }
                }
            }
            printf("\n");
        }
}

int main(int argv, char **args){
    char **nombreArchivo = &args[1];
	FILE *archivo;
	char caracter;
	archivo = fopen(*nombreArchivo,"r");
    char arregloMapa[2];
    int **arregloMapa2;
    int renglones=0;
    int columnas=0;
    int i=0,j=0;
	if (archivo == NULL){
        printf("\nError al abrir el archivo. \n\n");
    }
    else{
         while((caracter = fgetc(archivo)) != '\n'){//Leer el primer renglon y guardar valores de renglon y columna 
            if (isdigit(caracter)){
                arregloMapa[i]=caracter;
                i+=1;
            }  
        }
        renglones=arregloMapa[0] - '0';//volvemos a enteros los caracteres en char
        columnas=arregloMapa[1]  - '0';
        arregloMapa2=memoriaMatriz(renglones,columnas);
        i=0;
        while((caracter = fgetc(archivo)) != EOF){
            //printf("%c",caracter);
            if(caracter != '\n'){
                arregloMapa2[i][j]=caracter;
                if(arregloMapa2[i][j] == '.'){
                    arregloMapa2[i][j]=0 ;  
                }
                if(arregloMapa2[i][j] == '*'){
                    arregloMapa2[i][j]= '*' ;  
                }
                j+=1;
                if(j==renglones){
                    i+=1;
                    j=0;
                }
            }            
	    }
        //Lugar donde estan las bombas
        bombasActivas2(arregloMapa2,renglones,columnas);
        imprimeMatriz(arregloMapa2,renglones,columnas);
    }
    fclose(archivo);
	return 0;
}