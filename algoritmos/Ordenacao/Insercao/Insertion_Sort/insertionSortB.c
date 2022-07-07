#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void insertionSortB(int *array, int n);
void preencherArray(int *array, int n);
void imprimirArray(int *array, int n, bool estaOrdenado);

int main() {

    int t = 0;

    printf("Insertion Sort de outra forma - C\n\n");
    printf(" Entre com o tamanho do Array de Inteiros: ");
    scanf("%d", &t);

    int *array = (int*) malloc(t * sizeof(int));
    preencherArray(array, t); // insere números randômicos no array.

    printf("Ordenacao");
    
    imprimirArray(array, t, false);
    insertionSortB(array, t); // algoritmo de ordenação.
    imprimirArray(array, t, true); // função para imprimir o array ordenado no final.

    printf("\n\n");
    free(array);

    return 0;
}

void insertionSortB(int *array, int n) {

    // instrução de repetição que percorre todo o array
    for (int i = 1; i < n; i++) {

        /* comparação se i não é nulo, ou seja, se ainda há índice para serem comparados.
         * também é comparado se o valor no índice i é maior que o valor atual. Caso seja,
         * o valor no i é passado pra frente e i é decrementado. Isso é feito x vezes.
         */
        for (int j = i; j > 0; j--) {
            if (array[j] < array[j-1]) {
                int aux = array[j-1];
                array[j-1] = array[j];
                array[j] = aux;
            }
        }
    }

}

void preencherArray(int *array, int n) {

    srand(time(0));

    for(int i = 0; i < n; i++) {
        array[i] = (rand() % 100) + 1;
    }

}

void imprimirArray(int *array, int n, bool estaOrdenado) {

    if (estaOrdenado){
        printf("\n Array Ord.   [] = ");
    } else {
        printf("\n Array Desord.[] = ");
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

}
