#include <iostream>
#include <string>

int buscaBinaria(int *array, int inicio, int fim, int chave);
void imprimirArray(int* array, int tamanho, std::string texto);
void gerarArray(int *array, int tamanho);

int main() {

    int tamanho = 0, chave = 0;

    std::cout << "Busca Binária - C++\n\n"
    << " Digite o tamanho do array: ";
    std::cin >> tamanho;

    int *array = new int[tamanho];
    gerarArray(array, tamanho);
    imprimirArray(array, tamanho, " Array gerado: ");

    std::cout << " Digite um valor para ser procurado dentro do array: ";
    std::cin >> chave;

    int indice = buscaBinaria(array, 0, tamanho, chave);

    if (indice < 0) {
        std::cout << " \nO valor procurado não existe no array\n";
    } else {
        std::cout << " \nO valor procurado está no índice " 
        << indice << "\n";
    }

    std::cout << "Fim do programa.\n";

    return EXIT_SUCCESS;
}

int buscaBinaria(int *array, int inicio, int fim, int chave) {

    int tamanho = sizeof(array) / sizeof(int);

    if (fim >= inicio) {
        int meio = (fim + inicio) / 2;

        if (array[meio] == chave) {
            return meio;
        }

        if (array[meio] > chave) {
            return buscaBinaria(array, inicio, meio-1, chave);
        }

        return buscaBinaria(array, meio+1, fim, chave);
    }

    return -1;

}

void imprimirArray(int* array, int tamanho, std::string texto) {

    std::cout << texto;
    for (int i = 0; i < tamanho; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

}

void gerarArray(int *array, int tamanho) {

    srand(time(0));
    for (int i = 0; i < tamanho; i++) {
        array[i] = (rand() % 100) + 1; // vai de 1 até 100.
    }

}