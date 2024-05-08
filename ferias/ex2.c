#include <stdio.h>
#include <stdlib.h>

#define MAX 256

int main()
{

    int i, j;
    int m;
    int somaTot = 0;
    int somaMAx = 0;

    int *matriz;
    int *line;
    int *col;

    scanf("%d", &m);
    matriz = malloc(sizeof(int) * m * m);
    line = malloc(sizeof(int) * m);
    col = malloc(sizeof(int) * m);

for (j=0;j<m;j++) {col[j]=0;}
    for (i = 0; i < m; i++) {line[i] = 0;}


   for (i = 0; i < (m); i++)
    {

        for (j = 0; j < m; j++){

         scanf("%d", &matriz[i * m + j]);


        }
        }

    for (i = 0; i < (m); i++)
    {

        for (j = 0; j < m; j++)
        {
           
            line[i] += matriz[i*m+j];
            col[j] += matriz[i*m+j];
        }
    }

       
    for (i=0;i<m;i++){

        for(j=0;j<m;j++){

            somaTot = line[i] + col[j] - 2*matriz[i*m+j];
            if(somaTot > somaMAx){

                somaMAx = somaTot;
            }

        }


    }

    printf("\n%d\n", somaMAx);
    return 0;
    free(matriz);
    free(line);
    free(col);
}