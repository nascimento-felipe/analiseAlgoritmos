#include <iostream>

void quickSort(int *array, int inicio, int fim);
void gerarArray(int *array, int tamanho);
void imprimirArray(int *array, int tamanho, std::string frase);

int main() {

    int const tamanho = 15;
    int *array = new int[tamanho];
    gerarArray(array, tamanho);

    std::cout << "---------- Metodos de Ordenacao por Selecao ----------\n\n";
    std::cout << " 4) Quick Sort\n";

    imprimirArray(array, tamanho, "  Vetor Desord.[] = ");
    quickSort(array, 0, tamanho - 1);
    imprimirArray(array, tamanho, "  Vetor Ord.   [] = ");

    delete[] array;

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

void imprimirArray(int *array, int tamanho, std::string frase) {

    std::cout << frase;
    for (int i = 0; i < tamanho; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

}