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

    delete [] array;
    return 0;
}

void insertionSort(int* array, int n) {

    int chave = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
        chave = array[i];
        j = i - 1;

        while(j >= 0 && array[j] > chave) {
            array[j+1] = array[j];
            j--;
        }

        array[j+1] = chave; 
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