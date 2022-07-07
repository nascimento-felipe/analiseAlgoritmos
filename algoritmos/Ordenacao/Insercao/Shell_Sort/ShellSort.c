#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shellSort(int *array, int tamanho, int Inc, int SegCorrente);
void gerarArray(int *array, int tamanho);
void imprimirArray(int *array, int tamanho, char *frase, int numeroInserido, int isNumeroInserido);

int main()
{
    int const tamanho = 15;
    int *array = (int*) malloc(tamanho * sizeof(int));
    gerarArray(array, tamanho);

    printf("---------- Metodos de Ordenacao por Insercao ----------\n\n");
    printf(" 3) Shell Sort\n");

    int const Np = 2;
    int Inc;
    for (int i = Np; i >= 0; i--) {
        Inc = (int)(i*i);
        for (int SegCorrente = 0; SegCorrente < Inc; SegCorrente++) {
            shellSort(array, tamanho, Inc, SegCorrente);
        }
    }

    imprimirArray(array, tamanho, "\n  Vetor Ord.   [] = ", 0, 0);

    free(array);

    return 0;
}

void shellSort(int *array, int tamanho, int Inc, int SegCorrente) {

    int i = 0, j = 0, chave = 0, k = 0;

    for (i = (SegCorrente+Inc); i < tamanho; i+=Inc) {
        k = SegCorrente;
        j = i - Inc;
        chave = array[i];
        imprimirArray(array, tamanho, "  Vetor Desord.[] = ", chave, 1);

        while ((j>=SegCorrente) && (k == SegCorrente)) {
            if (chave < array[j]) {
                array[j+Inc] = array[j];
                j = j-Inc;
            } else {
                k = j + Inc;
            }
        }

        array[k] = chave;
    }

}

void gerarArray(int *array, int tamanho) {

    srand(time(0));

    for (int i = 0; i < tamanho; i++) {
        array[i] = (rand() % 100) + 1;
    }

}

void imprimirArray(int *array, int tamanho, char *frase, int numeroInserido, int isNumeroInserido) {

    printf("%s", frase);
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }

    if (isNumeroInserido == 1) {
        printf("- %d\n", numeroInserido);
    } else {
        printf("\n");
    }

}