#include <stdio.h>

long int fatorial(int n){
    int i;
    long int fat = 1;

    for(i = 1; i <= n; i++){
        fat = fat * i;
    }

    return fat;
}

int main(void){
    int n;
    printf("Digite um número: ");
    scanf("%d", &n);

    printf("O fatorial de %d é %ld\n", n, fatorial(n));

    return 0;
}
