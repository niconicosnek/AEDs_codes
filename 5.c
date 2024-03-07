//5. Implemente a função de Fibonacci com um algoritmo de complexidade O(n).

#include <stdio.h>
#include <stdlib.h>

int main () {

    int index;

    scanf("%d", &index);

    int *fib = (int*)malloc(index * sizeof(int));

    fib[0] = 0;
    fib[1] = 1;
    printf("%d ", fib[1]);
    for (int i = 2; i <= index; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
        printf("%d ", fib[i]);
    }
    printf("\n");

    free(fib);
    fib = NULL;

    return 0;
}