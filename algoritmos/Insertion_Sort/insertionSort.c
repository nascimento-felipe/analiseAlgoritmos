#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void ordenaArray(int *array, int n);
void preencherArray(int *array, int n);
void imprimirArray(int *array, int n, bool estaOrdenado);

int main() {

    int t = 0;

    printf(" Entre com o tamanho do Array de Inteiros: ");
    scanf("%d", &t);

    int *array = (int*) malloc(t * sizeof(int));

    preencherArray(array, t); // insere números randômicos no array.

    printf("Ordenacao");
    
    imprimirArray(array, t, false);
    ordenaArray(array, t); // algoritmo de ordenação.
    imprimirArray(array, t, true); // função para imprimir o array ordenado no final.

    printf("\n\n");
    free(array);

    return 0;
}

void ordenaArray(int *array, int n) {

    // inicialização das variáveis
    int i = 0; // representa o índice atual - n, no qual o valor atual será comparado
    int chave = 0; // representa o valor armazenado no array no índice atual

    // instrução de repetição que percorre todo o array
    for (int j = 1; j < n; j++) {
        chave = array[j]; // passagem do valor no índice j para a variável chave
        i = j - 1;  // variável de controle i recebe o índice - 1

        /* comparação se i não é nulo, ou seja, se ainda há índice para serem comparados.
         * também é comparado se o valor no índice i é maior que o valor atual. Caso seja,
         * o valor no i é passado pra frente e i é decrementado. Isso é feito x vezes.
         */
        while (i >= 0 && array[i] > chave) {
            array[i+1] = array[i];
            i = i - 1;
        }

        /* caso o não existam mais índices para comparar ou o valor atual é maior que o
         * índice comparado, o valor chave é inserido na posição em frente do índice i.
         */
        array[i+1] = chave;
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
