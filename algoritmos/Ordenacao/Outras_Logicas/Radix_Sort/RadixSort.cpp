#include <iostream>

void radixSort(int *array, int tamanho);                    /// função que ordena um array usando a lógica do raixSort.
void gerarArray(int *array, int tamanho);                   /// função que gera um array de forma pseudoaleatória.
void imprimirArray(int *array, int tamanho, std::string frase);   /// função que imprime um array no console.

int main() {

    std::cout << " ---------- Algoritmos com outros metodos ----------\n\n";
    std::cout << "2) Radix Sort:\n";

    int const tamanho = 20;
    int *array = new int[tamanho];
    gerarArray(array, tamanho);

    imprimirArray(array, tamanho, "  Array Desord.[] = ");
    radixSort(array, tamanho);
    imprimirArray(array, tamanho, "  Array Ord.   [] = ");

    delete[] array;

    return 0;
}

/**
 * função radixSort(): ordena um array usando a lógica do radixSort
 *  - O(n).
 * 
 * Parâmetros:
 *  - int *array: array para ser ordenado.
 *  - int tamanho: tamanho do array que vai ser ordenado.
 * 
 * Retorno
 *  - void.
 */
void radixSort(int *array, int tamanho) {

    int maior = 0, exp = 1;
    int *b = new int[tamanho];

    for (int i = 0; i < tamanho; i++) {
        if (array[i] > maior) {
            maior = array[i];
        }
    }

    while (maior/exp > 0) {
        int bucket[10] = {0};

        for (int i = 0; i < tamanho; i++) {
            bucket[array[i]/exp%10]++;
        }

        for (int i = 1; i < 10; i++) {
            bucket[i]+=bucket[i-1];
        }

        for (int i = tamanho-1; i >= 0; i--) {
            b[--bucket[array[i]/exp%10]] = array[i];
        }

        for (int i = 0; i < tamanho; i++) {
            array[i] = b[i];
        }

        exp*=10;
    }

    delete[] b;
}

/**
 * função gerarArray(): gera um array de forma pseudoaleatória
 * usando a função srand() e rand().
 * 
 * Parâmetros:
 *  - int *array: array de inteiros pra receber os inteiros.
 *  - int tamanho: tamanho do array.
 * 
 * Retorno:
 *  - void. 
 */
void gerarArray(int *array, int tamanho) {

    srand(time(0));
    for (int i = 0; i < tamanho; i++) {
        array[i] = rand() % 100;
    }

}

/**
 * função imprimirArray(): mostra o array no console depois de
 * mostrar uma frase passada como argumento.
 * 
 * Parâmetros:
 *  - int *array: array de inteiros pra receber os inteiros.
 *  - int tamanho: tamanho do array.
 *  - char *frase: frase pra ser mostrada antes de apresentar o array.
 * 
 * Retorno:
 *  - void. 
 */
void imprimirArray(int *array, int tamanho, std::string frase) {

    std::cout << frase;
    for (int i = 0; i < tamanho; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

}