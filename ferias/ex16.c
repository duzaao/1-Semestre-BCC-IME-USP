#include <stdio.h>
#include <string.h>


char *disemvowel(const char *str)
{

const char *res;
int j = strlen(str);
int i, k;

res = malloc(sizeof(const char)*j);

for (i=0;i<j;i++){

if((str[i] != " ") && (str[i] != "a") && (str[i] != "e") && (str[i] != "i") && (str[i] != "o") && (str[i] != "u") && (str[i] != "A") && (str[i] != "E") && (str[i] != "I") && (str[i] != "O") && (str[i] != "U")) {

res[k] = str[i];
k++;
}


}




  return res;
}

