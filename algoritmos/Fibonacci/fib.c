#include <stdio.h>
#include <stdlib.h>

int fibonacciIterativo(int n);
int fibonacciRecursivo(int n);

int main() {

    int numSerie;

    printf("Digite o valor da série de fibonacci: ");
    scanf("%d", &numSerie);

    int resultado = fibonacciIterativo(numSerie);

    printf("Valor da serie no num escolhido: %d\n", resultado);

    return 0;
}

int fibonacciIterativo(int n) {
    
    int fib = 0;
    for (int i = n-1; i > 2; i--) {
        fib = fib + (i-1) + (i-2);
    }

    return fib;

}

// não usei essa função na main, porém se quiser pode testar. Só leia o readme
// para entender o porque não é recomendado usar essa função.
int fibonacciRecursivo(int n) {

    if (n < 2) {
        return 1;
    } else {
        return fibonacciRecursivo(n-1) + fibonacciRecursivo(n-2);
    }

}