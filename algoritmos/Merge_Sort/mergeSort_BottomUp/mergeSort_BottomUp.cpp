#include <iostream>
#include <string>
#include <time.h>

int min(int x, int y);
void mergeSort_BottomUp(int array[], int tamanho);
void merge(int array[], int tamanho, int comeco, int meio, int fim);
void imprimir(int array[], int tamanho, std::string texto);
void gerarArray(int* array, int tamanho); 

int main(void) {

    int tamanhoArray = 0;

    std::cout << "Merge Sort Bottom Up (MS iterativo) - Cpp\n\n";
    std::cout << " Digite o tamanho do array: ";
    std::cin >> tamanhoArray;

    int* array = new int[tamanhoArray];
    gerarArray(array, tamanhoArray);

    imprimir(array, tamanhoArray, " Array Desordenado: ");
    mergeSort_BottomUp(array, tamanhoArray);
    imprimir(array, tamanhoArray, " Array Ordenado...: ");

    delete [] array;

    return EXIT_SUCCESS;
}

void mergeSort_BottomUp(int array[], int tamanho) {

    for (int i = 1; i < tamanho; i *= 2) {
        for (int comeco = 0; comeco < tamanho - 1; comeco += 2*i) {
            int meio = min(comeco + i - 1, tamanho - 1);
            int fim = min(comeco + 2*i - 1, tamanho - 1);
            merge(array, tamanho, comeco, meio, fim);
        }
    }

}

void merge(int array[], int tamanho, int comeco, int meio, int fim) {

    int* b = new int[tamanho];

    for (int i = comeco; i <= meio; i++) {
        b[i] = array[i];
    }

    for (int j = meio+1; j <= fim; j++) {
        b[fim+meio+1-j] = array[j];
    }

    int i = comeco;
    int j = fim;

    for (int k = comeco; k <= fim; k++) {
        if(b[i] <= b[j]) {
            array[k] = b[i];
            i++;
        } else {
            array[k] = b[j];
            j--;
        }
    }

    delete [] b;

}

void imprimir(int array[], int tamanho, std::string texto) {

    std::cout << texto;

    for (int i = 0; i < tamanho; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << "\n";

}

int min(int x, int y) {
    return (x<y) ? x:y;
}

void gerarArray(int* array, int tamanho) {

    srand(time(0));

    for (int i = 0; i < tamanho; i++) {
        array[i] = (rand() % 100) + 1;
    }

}