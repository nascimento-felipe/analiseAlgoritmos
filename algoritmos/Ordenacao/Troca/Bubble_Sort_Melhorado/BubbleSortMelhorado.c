#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *array, int tamanho);
void imprimirArray(int *array, int tamanho, char *frase);
void gerarArray(int *array, int tamanho);

int main()
{
    int const tamanho = 15;
    int *array = (int*) malloc(tamanho * sizeof(int));
    gerarArray(array, tamanho);

    printf("---------- Metodos de Ordenacao por Troca ----------\n\n");
    printf(" 2) Bubble Sort Melhorado\n");

    bubbleSort(array, tamanho);
    imprimirArray(array, tamanho, "  Vetor Ord.   [] = ");

    free(array);

    return 0;
}

void bubbleSort(int *array, int tamanho) {

    int aux = 0, i = 0, j = 0, troca = 1;


    imprimirArray(array, tamanho, "  Vetor Desord.[] = ");
    for (j = tamanho-1; (j >= 1) && (troca == 1); j--) {
        troca = 0;
        for (i = 0; i < j; i++) {
            if (array[i] > array[i+1]) {
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                troca = 1;
            }
        }
    }

}

void gerarArray(int *array, int tamanho) {

    srand(time(0));

    for (int i = 0; i < tamanho; i++) {
        array[i] = (rand() % 100) + 1;
    }

}

void imprimirArray(int *array, int tamanho, char *frase) {

    printf("%s", frase);
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

}