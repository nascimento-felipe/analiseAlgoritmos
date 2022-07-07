#include <iostream>
#include <time.h>

void insercaoBinaria(int *array, int tamanho);
void gerarArray(int *array, int tamanho);
void imprimirArray(int *array, int tamanho, std::string frase, int numeroInserido, int isNumeroInserido);

int main() {

    int const tamanho = 15;
    int *array = new int[tamanho];
    gerarArray(array, tamanho);

    std::cout << "---------- Metodos de Ordenacao por Insercao ----------\n\n";
    std::cout << " 2) Ordenacao Binaria\n";

    insercaoBinaria(array, tamanho);
    imprimirArray(array, tamanho, "\n  Vetor Ord.   [] = ", 0, 0);

    delete[] array;

    return EXIT_SUCCESS;

}

void insercaoBinaria(int *array, int tamanho) {

    int i = 0, j = 0;
    int m = 0, chave = 0;
    int L = 0, R = 0;

    for (i = 1; i < tamanho; i++) {
        chave = array[i];
        imprimirArray(array, tamanho, "  Vetor Desord.[] = ", chave, 1);
        L = 0;
        R = i;

        while (L < R) {
            m = (L + R) / 2;
            if (chave >= array[m]) {
                L = m + 1;
            } else {
                R = m;
            }
        }

        for (j = i; j > L; j--) {
            array[j] = array[j-1];
        }

        array[R] = chave;
    }

}

void gerarArray(int *array, int tamanho) {

    srand(time(0));

    for (int i = 0; i < tamanho; i++)
        array[i] = (rand() % 100) + 1;

}

void imprimirArray(int *array, int tamanho, std::string frase, int numeroInserido, int isNumeroInserido) {

    std::cout << frase;

    for (int i = 0; i < tamanho; i++)
        std::cout << array[i] << " ";

    if (isNumeroInserido == 1)
        std::cout << "- " << numeroInserido << std::endl; 
        // printf("- %d\n", numeroInserido);
    else
        std::cout << "\n";

}