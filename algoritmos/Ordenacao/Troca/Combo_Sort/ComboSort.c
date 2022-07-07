#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void combSort(int *array, int tamanho);
void imprimirArray(int *array, int tamanho, char *frase);
void gerarArray(int *array, int tamanho);

int main()
{
    int const tamanho = 15;
    int *array = (int*) malloc(tamanho * sizeof(int));
    gerarArray(array, tamanho);

    printf("---------- Metodos de Ordenacao por Troca ----------\n\n");
    printf(" 4) Comb Sort\n");

    imprimirArray(array, tamanho, " Vetor Desord.[] = ");
    combSort(array, tamanho);
    imprimirArray(array, tamanho, " Vetor Ord.   [] = ");

    return 0;
}

void combSort(int *array, int tamanho) {

    double h = tamanho;
    int aux, i, troca;

    do {

        h = h/1.3;
        if ((h == 9) || (h == 10)) {
            h = 11;
        }

        troca = 0;

        for (int i = 0; i < (tamanho-h); i++) {
            if (array[(int)i] > array[(int)(i+h)]) {
                aux = array[i];
                array[(int)i] = array[(int)(i+h)];
                array[(int)(i+h)] = aux;
                troca = 1;
            }
        }

    } while ((troca == 1) || (h >= 1));

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