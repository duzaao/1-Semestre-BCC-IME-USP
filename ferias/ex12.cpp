#include <cstdio>
#include <algorithm>

int vetor[100000];

int main() {

    int size;

    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        scanf("%d", vetor + i);
    }

    int sum;

    scanf("%d", &sum);

    for (int i = 0; i < size; i++) {

        int target = sum - vetor[i];

        int *valor = std::lower_bound(vetor, vetor + size, target);

        if (*valor == target) {
            printf("%d %d\n", vetor[i], target);
            break;
        }
    }


    return 0;
}