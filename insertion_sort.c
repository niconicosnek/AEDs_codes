#include <stdio.h>
#include <stdlib.h>

void insertion_sort (int *arr, int n);
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

void insertion_sort (int *arr, int n) {
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void print_arr (int *arr, int n) {
    printf("Array out of order: \n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertion_sort(arr, n);

    printf("Array in order: \n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}