/*6. Implemente uma função recursiva que inverta um vetor: 
void inverteVetor(int *vet, int inicio, int fim);*/

#include <stdio.h>
#include <stdlib.h>

void inverteVetor (int *vet, int inicio, int fim);
void imprimeVetor (int *vet, int n);

int main () {

    int n;

    scanf("%d", &n);

    int *vet = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        vet[i] = i;
    }

    imprimeVetor(vet, n);
    inverteVetor(vet, 0, n - 1);
    imprimeVetor(vet, n);

    return 0;
}

void imprimeVetor (int *vet, int n) {

    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");

}

void inverteVetor (int *vet, int inicio, int fim) {

    while(inicio <= fim){
        int temp = vet[inicio];
        vet[inicio] = vet[fim];
        vet[fim] = temp;
        return inverteVetor(vet, inicio + 1, fim - 1);
    }

}