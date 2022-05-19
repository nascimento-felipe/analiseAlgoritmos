#include <iostream>
#include <stdlib.h>
#include <string>

void insertionSort(int* array, int n);
void gerarArray(int* array, int n);
void imprimirArray(int* array, int n, std::string texto);

int main() {

    int* array;
    int tamanhoArray = 0;
    std::string mensagem;

    std::cout << "Algoritmo de Insertion Sort na linguagem C++\n" << std::endl;

    std::cout << " Digite o tamanho do array: ";
    std::cin >> tamanhoArray; 
    
    array = new int[tamanhoArray];

    gerarArray(array, tamanhoArray);
    std::cout << std::endl;
    
    mensagem = " Array desordenado: ";
    imprimirArray(array, tamanhoArray, mensagem);
    insertionSort(array, tamanhoArray);

    std::cout << std::endl;

    mensagem = " Array ordenado...: ";
    imprimirArray(array, tamanhoArray, mensagem);
    std::cout << "\n";

    delete [] array;
    return 0;
}

void insertionSort(int* array, int n) {

    for (int i = 0; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (array[j] < array[j-1]) {
                int aux = array[j-1];
                array[j-1] = array[j];
                array[j] = aux;
            }
        }
    }

}

void gerarArray(int* array, int n) {

    srand(time(0));

    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100;
    }

}

void imprimirArray(int* array, int n, std::string texto) {

    std::cout << texto;
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }

}