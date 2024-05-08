#include <stdio.h>
#include <stdlib.h>

#define MAX 256

int main()
{

    int m, n;

    scanf("%d %d", &m, &n);

    if (n == m)
    {
        printf("1");
    }
    else if (m < n)
    {
        if ((m * n) % 2 == 0)
        {
            printf("0");
        }
        else
        {
            printf("1");
        }
    }

    else
    {
        if ((m * n) % 2 == 0)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }

    return 0;
}