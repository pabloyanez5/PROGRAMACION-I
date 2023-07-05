#include <stdio.h>
#include <stdlib.h>

/*Escribir un programa que pida un numero entero entre 1 y 10
y guarde en un fichero de texto de nombre tabla-n.txt la tabla de ese numero,
donde n es el numero introducido.*/

int main()
{
    int numero;
    printf("Introduce un numero: \n");
    scanf("%d",&numero);

    FILE *f;
    f = fopen("tabla.txt","w");
    for (int i=0; i<=10; i++){
        fprintf(f,"%d\n",i*numero);
    }

    fclose(f);
}
