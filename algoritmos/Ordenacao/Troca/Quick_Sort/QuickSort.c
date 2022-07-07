#include <stdio.h>
#include <stdlib.h>

void quickSort(int *array, int inicio, int fim);
void gerarArray(int *array, int tamanho);
void imprimirArray(int *array, int tamanho, char *frase);

int main() {

    int const tamanho = 15;
    int *array = (int*) malloc(tamanho * sizeof(int));
    gerarArray(array, tamanho);

    printf("---------- Metodos de Ordenacao por Selecao ----------\n\n");
    printf(" 4) Quick Sort\n");

    imprimirArray(array, tamanho, " Vetor Desord.[] = ");
    quickSort(array, 0, tamanho);
    imprimirArray(array, tamanho, " Vetor Ord.   [] = ");

    return 0;
}

void quickSort(int *array, int inicio, int fim) {

    int pivo, aux, i, j, meio;

    i = inicio;
    j = fim;

    meio = (int) ((i+j) / 2);
    pivo = array[meio];

    do {

        while (array[i] < pivo) i++;
        while (array[j] > pivo) j--;

        if (i <= j) {
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--;
        }
    } while (j > i);

    if (inicio < j) {
        quickSort(array, inicio, j);
    }

    if (i < fim) {
        quickSort(array, i, fim);
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