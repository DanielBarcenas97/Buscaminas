#include <stdio.h>
#include <string.h>
 
int main(){
FILE *fp1;
int i,j;
float A[3][3], B[3][3];
int c;
 
fp1 = fopen("datos.txt", "r");   //Abrimo  el archivo
 
for(i=0;i<3;i++)                                   //Iteramos i,j para  ir almacenando los valores.
    for(j=0;j<3;j++)
    {        
        fscanf(fp1, "%f", &A[i][j]);            // Leemos un float y lo guardamos en A en la posicion i,j
        fscanf(fp1, "%f", &B[i][j]);            // Leemos un float y lo guardamos en B en la posicion i,j
        printf("Matriz A: %.2f \n", A[i][j]);
        printf("Matriz B: %.2f \n", B[i][j]);
    }               
fclose(fp1);
 
system("PAUSE");
return 0;
}