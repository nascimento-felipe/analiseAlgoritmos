#include <iostream>
#include <time.h>

void shakeSort(int *array, int tamanho);
void imprimirArray(int *array, int tamanho, std::string frase);
void gerarArray(int *array, int tamanho);

int main()
{
    int const tamanho = 15;
    int *array = new int[tamanho];
    gerarArray(array, tamanho);

    std::cout << "---------- Metodos de Ordenacao por Troca ----------\n\n";
    std::cout << " 3) Shake Sort\n";

    imprimirArray(array, tamanho, "  Vetor Desord.[] = ");
    shakeSort(array, tamanho);
    imprimirArray(array, tamanho, "  Vetor Ord.   [] = ");

    delete[] array;

    return 0;
}

void shakeSort(int *array, int tamanho) {

    int L = 0, R = tamanho-1, k = R;
    int j, aux;

    do {

        for (j = L; j < R; j++) {
            if (array[j] > array[j+1]) {
                aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
                k = j;
            }
        }

        R = k;

        for (j = R; j > L; j--) {
            if (array[j-1] > array[j]) {
                aux = array[j-1];
                array[j-1] = array[j];
                array[j] = aux;
                k = j;
            }
        }
        L = k;
    } while (L < R);

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