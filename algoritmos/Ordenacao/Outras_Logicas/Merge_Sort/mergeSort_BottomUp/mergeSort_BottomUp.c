#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int min(int x, int y);
void mergeSort_BottomUp(int *array, int tamanho);
void merge(int* array, int tamanho, int comeco, int meio, int fim);
void imprimir(int* array, int tamanho, char* texto);
void gerarArray(int* array, int tamanho);

int main() {

    int tamanho;

    printf("Merge Sort Bottom Up (MS Iterativo) - C\n\n");
    printf(" Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int* array = (int*) malloc(tamanho * sizeof(int));
    gerarArray(array, tamanho);

    imprimir(array, tamanho, " Array Desordenado: ");
    mergeSort_BottomUp(array, tamanho);
    imprimir(array, tamanho, " Array Ordenado...: ");

    printf("\nFim do programa.\n");
    free(array);

    return EXIT_SUCCESS;

}


int min(int x, int y) {
    return (x < y) ? x : y;
}

void mergeSort_BottomUp(int *array, int tamanho) {

    for (int i = 1; i < tamanho; i *= 2) {
        for (int comeco = 0; comeco < tamanho-1; comeco += 2*i) {
            int meio = min(comeco + i - 1, tamanho - 1);
            int fim = min(comeco + 2*i - 1, tamanho - 1);
            merge(array, tamanho, comeco, meio, fim);
        }
    }

}

void merge(int* array, int tamanho, int comeco, int meio, int fim) {

    int *b = (int*) malloc(tamanho * sizeof(int));

    for (int i = comeco; i <= meio; i++) {
        b[i] = array[i];
    }

    for (int j = meio+1; j <= fim; j++) {
        b[fim+meio+1-j] = array[j];
    }

    int i = comeco;
    int j = fim;

    for (int k = comeco; k <= fim; k++) {
        if (b[i] <= b[j]) {
            array[k] = b[i];
            i++;
        } else {
            array[k] = b[j];
            j--;
        }
    }

    free(b);

}

void imprimir(int* array, int tamanho, char* texto) {
    
    printf("\n%s", texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

}

void gerarArray(int* array, int tamanho) {

    srand(time(0));
    for (int i = 0; i < tamanho; i++) {
        array[i] = (rand() % 100) + 1;
    }

}
