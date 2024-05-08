#include <stdio.h>
#include <stdlib.h>


int main()
{

int n,i,j, aux;
int *vetor;

scanf("%d", &n);
vetor = malloc(sizeof(int)*n);

for(i=0;i<n;i++){

    scanf("%d", &vetor[i]);
}

for (i=0;i<n;i++){

    for(j=i;j<n;j++){

        if(vetor[i] > vetor[j]){
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
        }

    }
}

for(i=0;i<n;i++){

    printf("%d ", vetor[i]);
}
free(vetor);
return 0;
}