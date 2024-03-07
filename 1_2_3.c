/*1. Implemente a função da busca sequencial com a seguinte declaração:
int buscaSequencial(int elem, int *vet, int n);
2. Implementa a função da busca binária com as seguintes declarações:
    a) int buscaBinaria(int elem, int *vet, int n);
    b) int buscaBinariaRecursiva(int elem, int* vet, int a, int b);
3. Compare a busca binária e sequencial em relação ao número de comparações com
um vetor ordenado de tamanho 100 e depois com um de tamanho 1000.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int buscaSequencial (int elem, int *arr, int n);
int buscaBinaria (int elem, int *arr, int n);
int buscaBinariaRec (int elem, int *arr, int a, int b);

int main () {

    int n, elem;

    printf("Enter size of the array: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++){
        arr[i] = i + 1;
    }

    printf("Enter the element to search: ");
    scanf("%d", &elem);

    int resultSeq = buscaSequencial (elem, arr, n);
    if (resultSeq != -1){
        printf("Sequencial Search - Element found at index: %d\n", resultSeq);
    } else {
        printf("Element not found\n");
    }

    int resultBin = buscaBinaria (elem, arr, n);
    if (resultBin != -1){
        printf("Binary Search (Iterative) - Element found at index: %d\n", resultBin);
    } else {
        printf("Element not found\n");
    }

    int resultRec = buscaBinariaRec (elem, arr, 0, n - 1);
    if (resultRec != -1){
        printf("Binary Search (Recursive) - Element found at index: %d\n", resultRec);
    } else {
        printf("Element not found\n");
    }

    free(arr);
    return 0;
}

int buscaSequencial (int elem, int *arr, int n) {
    int counter = 0;
    for (int i = 0; i < n; i++){
        counter++;
        if (arr[i] == elem){
            printf("Sequencial Search - Array accesses: %d\n", counter);
            return i;
        }
    }
    printf("Sequencial Search - Array accesses: %d\n", counter);
    return -1;
}

int buscaBinaria (int elem, int *arr, int n) {
    int counter = 0;
    int start = 0, end = n - 1;
    int middle;

    while (start <= end){
        counter++;
        middle = (start + end)/2;
        if (arr[middle] == elem){
            printf("Binary Search (Iterative) - Array accesses: %d\n", counter);
            return middle;
        } else if (arr[middle] < elem){
            start = middle + 1;
        } else if (arr[middle] > elem){
            end = middle - 1;
        }
    }
    printf("Binary Search (Iterative) - Array accesses: %d\n", counter);
    return -1;
}

int buscaBinariaRec (int elem, int *arr, int a, int b) {
    static int counter = 0;
    counter++;

    if (a > b){
        return -1;
    }

    int middle = (a + b)/2;

    if (arr[middle] == elem){
        printf("Binary Search (Recursive) - Array accesses: %d\n", counter);
        return middle;
    } else if (arr[middle] > elem){
        return buscaBinariaRec (elem, arr, a, middle - 1);
    } else if (arr[middle] < elem){
        return buscaBinariaRec (elem, arr, middle + 1, b);
    }
}