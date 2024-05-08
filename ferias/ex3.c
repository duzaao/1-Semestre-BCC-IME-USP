#include <stdio.h>
#include <stdlib.h>

#define MAX 256

int main()
{

int a, b;
int i;
int aux;

scanf ("%d %d", &a, &b);

if (a>b){
aux = b;
b = a;
a = aux;
}

for (i = a; i<=b; i++){

    printf ("%d ", i);
}
return 0;
}