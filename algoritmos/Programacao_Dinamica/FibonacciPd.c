#include <stdio.h>
#include <stdlib.h>

int fibPdRecursivo(int sequencia[], int valor);
int fibPdIterativo(int sequencia[], int valor);


int main() {

    int valor = 0;
    int *array = (int*) malloc((valor+1) * sizeof(int));

    printf("Digite o valor a ser procurado: ");
    scanf("%d", &valor);

    for (int i = 0; i <= valor; i++) {
        array[i] = -1;
    }

    printf("Valor de Fibonacci na %dº posicao (recursivo): %d\n", valor, fibPdRecursivo(array, valor));
    printf("Valor de Fibonacci na %dº posicao (iterativo): %d\n", valor, fibPdRecursivo(array, valor));

}

int fibPdIterativo(int sequencia[], int valor) {

    sequencia[0] = 0;
    sequencia[1] = 1;

    for (int i = 2; i < valor; i++) {
        sequencia[valor] = sequencia[valor-1] + sequencia[valor-2];
    }

    return sequencia[valor];

}

int fibPdRecursivo(int sequencia[], int valor) {

    if (valor == 0) {
        return 0;
    }

    if (valor == 1) {
        return 1;
    }

    if (sequencia[valor] != -1) {
        return sequencia[valor];
    }

    sequencia[valor] = fibPdRecursivo(sequencia, valor-1) + fibPdRecursivo(sequencia, valor-2);
    
    return sequencia[valor];
}