#include <stdio.h>
#include <stdlib.h>

#define MAX 256

int main()
{

int x, y;

scanf ("%d %d", &x, &y);


if ((x == 0)||(y == 0)) { printf("eixos"); }
else if ((x>0) && (y>0)) { printf("Q1"); }
else if ((x>0) && (y<0)) { printf("Q4"); }
else if ((x<0) && (y>0)) { printf("Q2"); }
else  { printf("Q3"); }

return 0;
}