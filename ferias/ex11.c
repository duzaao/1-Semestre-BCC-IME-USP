#include <stdio.h>
#include <stdlib.h>


int main()
{

    int N, a, b, k;
    int i, j;
    int *casas;

    scanf("%d", &N);
    casas = malloc(sizeof(int) * N);

    for (i = 0; i < N; i++)
    {

        scanf("%d", &casas[i]);
    }

    scanf("%d", &k);

    for (i = 0; i < N; i++)
    {

        for (j = i+1; j < N; j++)
        {

            if (i != j)
            {

                if ((casas[i] + casas[j]) == k)
                {

                    a = casas[i];
                    b = casas[j];
                }
            }
        }
    }

    if (a > b)
    {

        printf("%d %d\n", b, a);
    }
    else
        printf("%d %d\n", a, b);

    free(casas);
    return 0;
}