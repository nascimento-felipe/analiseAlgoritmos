#include <iostream>

int fibIterativo(int nSerie);
int fibonacciRecursivo(int n);

int main(void) {

    int numeroSerie;

    std::cout << "Série de Fibonacci - Iterativo\n\n";
    std::cout << " Digite o valor da posição da série de Fibonacci: ";
    std::cin >> numeroSerie;

    int resul = fibIterativo(numeroSerie);

    std::cout << " O número da serie é: " << resul << "\n";


    return EXIT_SUCCESS;
}

int fibIterativo(int nSerie) {

    int r = 0;

    for (int i = nSerie - 1; i > 2; i--) {
        r += (i-1) + (i-2);
    }

    return r;

}

// não usei essa função na main, porém se quiser pode testar. Só leia o readme
// para entender o porque não é recomendado usar essa função.
int fibonacciRecursivo(int n) {

    if (n < 2) {
        return 1;
    } else {
        return fibonacciRecursivo(n-1) + fibonacciRecursivo(n-2);
    }

}