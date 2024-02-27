#include <stdio.h>

int fatorial (int n);

int main () {

    int n, fat = 1;

    scanf("%d", &n);

    /*for (int i = 1; i <= n; i++){
        fat *= i;
    }*/

    printf("%d\n", fatorial(n));

    return 0;
}

int fatorial (int n) { //recursivo

    if (n <= 1){
        return 1;
    } else {
        return n * fatorial (n - 1);
    }
}