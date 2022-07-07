#include <stdio.h>
#include <stdlib.h>

void selectSort(int *array, int tamanho);                   /// função que ordena o array usando a lógica do selectSort
void gerarArray(int *array, int tamanho);                   /// função que gera um array de forma pseudoaleatória
void imprimirArray(int *array, int tamanho, char *frase);   /// função que imprime um array no console.

int main() {

    printf(" ---------- Algoritmos de Selecao ----------\n\n");
    printf(" 1) Select Sort:\n");

    int const tamanho = 20;
    int *array = (int*) malloc(tamanho * sizeof(int));
    gerarArray(array, tamanho);

    imprimirArray(array, tamanho, " Array Desord.[] = ");
    selectSort(array, tamanho);
    imprimirArray(array, tamanho, " Array Ord.   [] = ");

    free(array);

    return 0;
}

/**
 * função selectSort(): tem o objetivo de ordenar o array, usando a
 * lógica do select sort, onde é escolhido o menor elemento para
 * o menor índice do array, aumentando o menor índice a cada passagem.
 *  - O(n²)
 * 
 * Parâmetros:
 *  - int *array: array de inteiros que será ordenado.
 *  - int tamanho: tamanho do array que vai ser ordenado.
 * 
 * Retorno:
 *  - void.
 */
void selectSort(int *array, int tamanho) {

    int indiceMenor, menor, Comp;

    for (int i = 0; i < tamanho; i++) {
        Comp = 0;
        indiceMenor = i;
        menor = array[i];
        for (int j = i; j < tamanho; j++) {
            if (array[j] < menor) {
                indiceMenor = j;
                menor = array[indiceMenor];
                Comp = 1;
            }
        }
        if (Comp == 1) {
            array[indiceMenor] = array[i];
            array[i] = menor;
        }
    }

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