#include <iostream>
#include <math.h>
#include <time.h>

void shellSort(int *array, int tamanho, int Inc, int SegCorrente);
void gerarArray(int *array, int tamanho);
void imprimirArray(int *array, int tamanho, std::string frase, int numeroInserido, int isNumeroInserido);

int main()
{
    int const tamanho = 15;
    int *array = new int[tamanho];
    gerarArray(array, tamanho);

    std::cout << "---------- Metodos de Ordenacao por Insercao ----------\n\n";
    std::cout << " 3) Shell Sort\n";

    int const Np = 2;
    int Inc;
    for (int i = Np; i >= 0; i--) {
        Inc = (int)pow(2.0, i);
        for (int SegCorrente = 0; SegCorrente < Inc; SegCorrente++) {
            shellSort(array, tamanho, Inc, SegCorrente);
        }
    }

    imprimirArray(array, tamanho, "\n  Vetor Ord.   [] = ", 0, 0);
    
    delete[] array;
    
    return EXIT_SUCCESS;
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

void imprimirArray(int *array, int tamanho, std::string frase, int numeroInserido, int isNumeroInserido) {

    std::cout << frase;
    for (int i = 0; i < tamanho; i++) {
        std::cout << array[i] << " ";
    }

    if (isNumeroInserido == 1) {
        std::cout << "- " << numeroInserido << "\n";
    } else {
        std::cout << "\n";
    }

}