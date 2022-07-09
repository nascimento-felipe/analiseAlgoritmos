#include <iostream>

int procuraFibRecursivo(int* sequencia, int valor);
int procuraFibIterativo(int sequencia[], int valor);

int main() {

    int valor = 0;

    std::cout << "Digite o valor pra ser procurado: ";
    std::cin >> valor;

    int sequencia[valor+1];

    for (int i = 0; i <= valor; i++) {
        sequencia[i] = -1;
    }

    int resultadoRec = procuraFibRecursivo(sequencia, valor);
    int resultadoIte = procuraFibIterativo(sequencia, valor);

    std::cout << "Valor na" << valor <<"º posicao (recursivo): " << resultadoRec << "\n";
    std::cout << "Valor na" << valor <<"º posicao (iterativo): " << resultadoIte << "\n";

    return EXIT_SUCCESS;
}

int procuraFibIterativo(int sequencia[], int valor) {

    sequencia[0] = 0;
    sequencia[1] = 1;

    for (int i = 2; i < valor; i++) {
        sequencia[valor] = sequencia[valor-1] + sequencia[valor-2];
    }

    return sequencia[valor];

}

int procuraFibRecursivo(int sequencia[], int valor) {

    if (valor == 0) {
        return 0;
    }

    if (valor == 1) {
        return 1;
    }

    if (sequencia[valor] != -1) {
        return sequencia[valor];
    }

    sequencia[valor] = procuraFibRecursivo(sequencia, valor-1) + procuraFibRecursivo(sequencia, valor-2);

    return sequencia[valor];
}