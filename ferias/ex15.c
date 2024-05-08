#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>


uint64_t descendingOrder(uint64_t n)
{
  long int res = 0;
  int i, j=0, k=0;
  long int aux;
  long int *vet;
  long int x = n;

  for(i=0;x>0;i++){

    x = x/10;
  }

k = i;
x= n;
vet = malloc(sizeof(int)*k);

  for(i=0;i<k;i++){

vet[i] = x%10;
x = x/10;

  }

 

  for(i=0;i<k;i++){
    
    for(j=0;j<k;j++){

      if(vet[i] > vet[j]){

        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;


      }

    }
  }
  
    for(i = 0; i < k; i++){
        res = res*10 + vet[i];
    }


    free (vet);
    return res;
}












int main (){
uint64_t n = 123477856;
int x;


x = descendingOrder(n);
printf("%d", x);
  return 0;
}