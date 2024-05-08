#include <stdio.h> 
#include <stdlib.h>

#define MAX 256

int main(){


int i, j, n, q,a;

int ii;
int *lista;
int soma;

scanf ("%d",&n);
lista = malloc(sizeof(int)*n);
for (ii =0; ii< n; ii++){

scanf ("%d", &lista[ii]);

}

scanf ("%d", &q);

for (ii =0; ii< q; ii++){

soma = 0;
scanf ("%d %d", &i, &j);


if(((0 <= i) && (j <= n-1))){
for (a=i;a<=j;a++){

  soma  +=  lista[a];
}

printf ("%d",soma);
}}
return 0;
free(lista);
}