#include <iostream>
#include <stdlib.h>
#include <string>

void imprimirArray(int* array, int n, std::string texto);
void gerarArray(int* array, int n);
void mergeSort_R_SemSentinela(int* array, int n, int comeco, int fim);
void intercala(int* array, int n, int comeco, int meio, int fim);

int main() {

    int* array;
    int tamanhoArray = 0;
    std::string mensagem;

    std::cout << "Merge Sort Recursivo Sem Sentinela na linguagem C++\n\n";

    std::cout << " Digite o tamanho do array: ";
    std::cin >> tamanhoArray;

    array = new int[tamanhoArray];
    gerarArray(array, tamanhoArray);

    mensagem = "\n Array desordenado: ";
    imprimirArray(array, tamanhoArray, mensagem);
    
    mergeSort_R_SemSentinela(array, tamanhoArray, 0, tamanhoArray - 1);

    mensagem = "\n Array Ordenado...: ";
    imprimirArray(array, tamanhoArray, mensagem);
    std::cout << "\n\n";
    
    delete [] array;

    return 0;
}


void imprimirArray(int* array, int n, std::string texto) {

    std::cout << texto;
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }

}

void gerarArray(int* array, int n) {

    srand(time(0));
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100; // manipulacao pro array ter valores de 1~100.
    }

}

void mergeSort_R_SemSentinela(int* array, int n, int comeco, int fim) {

    if (comeco < fim) {
        //           0        7        = 3.5 -> 3
        int meio = (comeco + fim) / 2;
        mergeSort_R_SemSentinela(array, n, comeco, meio); // 0, 3
        mergeSort_R_SemSentinela(array, n, meio+1, fim); // 4, 7
        intercala(array, n, comeco, meio, fim);
    }

}

void intercala(int* array, int n, int comeco, int meio, int fim) {

    // debug de comentário: array[8].

    int* arrayAuxiliar = new int[n];

    for (int i = comeco; i <= meio; i++) {
        arrayAuxiliar[i] = array[i];
    }

    for (int j = meio+1; j <= fim; j++) {
        //            7 + 5 - 5 => 7
        //            7 + 5 - 6 => 6
        //            7 + 5 - 7 => 5
        //            7 + 5 - 8 ** NAO RODA ESSA ULTIMA VEZ PQ J == 8**
        arrayAuxiliar[fim+meio+1-j] = array[j];
    }

    int i = comeco;
    int j = fim;

    //             0           8
    for (int k = comeco; k <= fim; k++) {
        if(arrayAuxiliar[i] <= arrayAuxiliar[j]) {
            array[k] = arrayAuxiliar[i];
            i++;
        } else {
            array[k] = arrayAuxiliar[j];
            j--;
        }
    }

    delete [] arrayAuxiliar;

}