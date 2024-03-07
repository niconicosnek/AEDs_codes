/*4. Implemente novamente a função de Fibonacci com a seguinte modificação: a função
agora recebe um ponteiro para um inteiro chamado contador cujo valor para o qual
ele aponta é inicializado com 0 no início do main. Em cada chamada da função de
Fibonacci, incremente o valor para o qual o ponteiro aponta. Imprima o valor do
ponteiro após a execução para saber quantas vezes a função de Fibonacci foi chamada.*/

#include <stdio.h>

int fibonacci(int n, int *counter);

int main () {

    int n, counter = 0;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    int result = fibonacci(n, &counter);

    printf("Fibonacci number at position %d is: %d\n", n, result);
    printf("Number of function calls: %d\n", counter);

    return 0;
}

int fibonacci(int n, int *counter){

    (*counter)++;
    
    if (n <= 1){
        return n;
    } else {
        return fibonacci(n - 1, counter) + fibonacci(n - 2, counter);
    }
}