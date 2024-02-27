#include <stdio.h>

void tri (int n);
int pascal (int i, int j);

int main () {

    int n;

    scanf("%d", &n);

    tri(n);

    return 0;
}

void tri (int n) {


    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            printf("%d ", pascal(i, j));
        }
        printf("\n");
    }
}

int pascal (int i, int j) {

    if (i == j || j == 1){
        return 1;
    } else {
        return pascal (i - 1, j) + pascal (i - 1, j - 1);
    }
}