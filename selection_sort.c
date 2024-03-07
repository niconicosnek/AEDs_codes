#include <stdio.h>
#include <stdlib.h>

void troca (int *arr, int a, int b);
void selection_sort (int *arr, int n);
void print_arr (int *arr, int n);

int main () {

    int n;

    printf("Array size: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    print_arr(arr, n);

    free(arr);
    return 0;
}

void troca (int *arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void selection_sort (int *arr, int n) {
    int min;
    for (int i = 0; i < n - 1; i++){
        min = i;
        for (int j = i; j < n; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        troca(arr, i, min);
    }
}

void print_arr (int *arr, int n) {
    printf("Array out of order: \n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    selection_sort(arr, n);

    printf("Array in order: \n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}