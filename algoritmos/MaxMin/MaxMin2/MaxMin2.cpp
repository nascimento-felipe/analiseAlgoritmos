#include <iostream>
#include <time.h>
#include <string>

void gerarArray(int *array, int tamanho);
int* maxMin2(int *array, int tamanho);
void imprimirArray(int *array, int tamanho, std::string texto);

int main(void) {
    
    int tamanho = 0;

    std::cout 
    << "Maximo e Minimo 2 - Cpp\n\n"
    << " Digite o tamanho do array: ";
    
    std::cin >> tamanho;

    int* array = new int[tamanho];
    gerarArray(array, tamanho);
    imprimirArray(array, tamanho, " Array gerado: ");

    int *resultado = maxMin2(array, tamanho);

    std::cout 
    << "\n Valor máximo dentro do array: "
    << resultado[0]
    << "\n Valor mínimo dentro do array: "
    << resultado[1]
    << "\n\n"
    << "Fim do programa.\n";

    delete [] array;
    delete [] resultado;

    return EXIT_SUCCESS;
}

void gerarArray(int *array, int tamanho) {

    srand(time(0));
    for (int i = 0; i < tamanho; i++) {
        array[i] = (rand() % 500) - 250; // vai de -250 até 249.
    }

}

/**
 * MaxMin2(): Uma das funções para se achar o valor máximo e mínimo de uma lista de valores.
 *   Dentre os 3 algoritmos de MaxMin apresentados aqui, esse seria considerado "no meio" em questão de complexidade.
 *   A complexidade desse algoritmo varia, sendo:
 *     - 2n - 2         para o pior caso,
 *     - (3n/2) - 3/2   para o caso médio e
 *     - n - 1          para o melhor caso.
 * 
 * Parâmetros:
 *   - int *array: Array de inteiros em que serão procurados o maior e o menor valor.
 *   - int tamanho: Tamanho do array.
 * 
 * Retorno:
 *   Um array de 2 posições, contendo o valor máximo na primeira posição e o valor mínimo
 *   na segunda posição.
 * 
 */
int* maxMin2(int *array, int tamanho) {

    static int values[2];
    values[0] = array[0];
    values[1] = array[0];

    for (int i = 1; i < tamanho; i++) {
        if (array[i] > values[0]) { 
            values[0] = array[i];
        } else if (array[i] < values[1]) {
            values[1] = array[i];
        }
    }
    
    return values;

}

void imprimirArray(int* array, int tamanho, std::string texto) {

    std::cout << texto;
    for (int i = 0; i < tamanho; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

}