#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapSort(int *array, int tamanho);                     /// funçãoque ordena o array usando a lógica de Heap.
void heap(int E, int D, int *array);                        /// função auxiliar que mantém a lógica de Heap.
void gerarArray(int *array, int tamanho);                   /// função que gera um array de forma pseudoaleatória.
void imprimirArray(int *array, int tamanho, char *frase);   /// função que imprime um array no console.

int main() {

    printf(" ---------- Algoritmos de Selecao ----------\n\n");
    printf(" 2) Heap Sort:\n");

    int const tamanho = 20;
    int *array = (int*) malloc(tamanho * sizeof(int));
    gerarArray(array, tamanho);

    imprimirArray(array, tamanho, " Array Desord.[] = ");
    heapSort(array, tamanho);
    imprimirArray(array, tamanho, " Array Ord.   [] = ");

    free(array);
    return 0;

}

/**
 * função heapSort(): ordena um array usando a lógica de Heap.
 *  - O(n*lg(n)).
 * 
 * Parâmetros:
 *  - int *array: array para ser ordenado.
 *  - int tamanho: tamanho do array que vai ser ordenado.
 * 
 * Retorno
 *  - void.
 */
void heapSort(int *array, int tamanho) {

    int E, D, x;

    E = (tamanho/2)+1;
    D = tamanho-1;

    while (E > 0) {
        E--;
        heap(E, D, array);
    }

    while (D > 0) {
        x = array[0];
        array[0] = array[D];
        array[D] = x;
        D--;
        heap(E, D, array);
    }

}

/**
 * função heap(): mentém a lógica de árvore heap dentro do algoritmo
 * na função heapSort().
 * 
 * Parâmetros:
 *  - int E: valor do índice na esquerda do array.
 *  - int D: valor do índice na direita do array.
 *  - int *array: array para ser conferido.
 *  
 * Retorno
 *  - void.
 */
void heap(int E, int D, int *array) {

    int i, j, x;

    i = E;
    j = 2*E;
    x = array[E];

    if ((j < D) && (array[j] < array[j+1])) {
        j++;
    }

    while ((j <= D) && (x < array[j])) {
        array[i] = array[j];
        i = j;
        j = 2*j;
        if ((j < D) && (array[j] < array[j+1])) {
            j++;
        }
    }

    array[i] = x;

}

/**
 * função gerarArray(): gera um array de forma pseudoaleatória
 * usando a função srand() e rand().
 * 
 * Parâmetros:
 *  - int *array: array de inteiros pra receber os inteiros.
 *  - int tamanho: tamanho do array.
 * 
 * Retorno:
 *  - void. 
 */
void gerarArray(int *array, int tamanho) {

    srand(time(0));
    for (int i = 0; i < tamanho; i++) {
        array[i] = rand() % 100;
    }

}

/**
 * função imprimirArray(): mostra o array no console depois de
 * mostrar uma frase passada como argumento.
 * 
 * Parâmetros:
 *  - int *array: array de inteiros pra receber os inteiros.
 *  - int tamanho: tamanho do array.
 *  - char *frase: frase pra ser mostrada antes de apresentar o array.
 * 
 * Retorno:
 *  - void. 
 */
void imprimirArray(int *array, int tamanho, char *frase) {

    printf("%s", frase);
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

}