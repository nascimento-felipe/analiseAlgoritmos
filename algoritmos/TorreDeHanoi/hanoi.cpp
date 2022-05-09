#include <iostream>

void hanoi(int n, int origem, int aux, int destino);
void mover(int origem, int destino);

int main(void) {

    int quantidadeDiscos = 0;

    std::cout << "Torre de Hanoi - recursivo\n\n";

    std::cout << " Quantidade de torres = 3\n" 
    << " Digite a quantidade de discos: ";
    std::cin >> quantidadeDiscos;

    std::cout << "\n Movimentos: \n";
    hanoi(quantidadeDiscos, 1, 2, 3);
    std::cout << "Torre resolvida!\n";

    return EXIT_SUCCESS;
}


void hanoi(int n, int origem, int aux, int destino) {

    if (n > 0) {
        hanoi(n-1, origem, destino, aux);
        mover(origem, destino);
        hanoi(n-1, aux, origem, destino);
    }

}

void mover( int origem, int destino) {

    std::cout << " Mover disco da torre " << origem 
              << " para " << destino << "\n";

}