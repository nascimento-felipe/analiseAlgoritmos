#include <iostream>
#include <time.h>
#include <string>

void gerarArray(int *array, int tamanho);
int* maxMin3(int *array, int tamanho);
void imprimirArray(int *array, int tamanho, std::string texto);

int main(void) {
    
    int tamanho = 0;

    std::cout 
    << "Maximo e Minimo 3 - Cpp\n\n"
    << " Digite o tamanho do array: ";
    
    std::cin >> tamanho;

    int* array = new int[tamanho];
    gerarArray(array, tamanho);
    imprimirArray(array, tamanho, " Array gerado: ");

    int *resultado = maxMin3(array, tamanho);

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
 * MaxMin3(): Uma função com complexidade de tempo ótima ((3n/2) - 2). A ideia da função é
 *   retornar o maior e o menor valor de um array, passado como argumento, por meio de um 
 *   outro array de retorno.
 * 
 * Parâmetros:
 *   - int *array: array de inteiros em que serão buscados os valores.
 *   - int tamanho: tamanho do vetor.
 * 
 * Retorno:
 *   Um array de inteiros de 2 posições, em que a primeira posição é o maior valor
 *   e a segunda posição é o menor valor.
 *  
 */
int* maxMin3(int *array, int tamanho) {

    int max, min, FimDoAnel;
    if ((tamanho % 2) > 0) {
        array[tamanho] = array[tamanho-1];
        FimDoAnel = tamanho;
    } else {
        FimDoAnel = tamanho-1;
    }

    if (array[0] > array[1]) {
        max = array[0];
        min = array[1];
    } else {
        max = array[1];
        min = array[0];
    }

    int i = 2;

    while (i < FimDoAnel) {
        if (array[i] > array[i+1]) {
            if (array[i] > max) max = array[i];
            if (array[i+1] < min) min = array[i+1];
        } else {
            if (array[i] < min) min = array[i];
            if (array[i+1] > max) max = array[i+1];
        }

        i += 2;
    }

    static int* retorno = new int[2];
    retorno[0] = max; retorno[1] = min;

    return retorno;

}

void imprimirArray(int* array, int tamanho, std::string texto) {

    std::cout << texto;
    for (int i = 0; i < tamanho; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

}