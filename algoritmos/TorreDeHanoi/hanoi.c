#include <stdio.h>

void hanoi(int n, int origem, int aux, int destino);
void mover(int origem, int destino);

int main(void) {

    int quantidadeDiscos = 0;

    printf("Torre de Hanoi - recursivo\n\n");

    printf(" Quantidade de torres = 3\n");
    printf(" Digite a quantidade de discos: ");
    scanf("%d", &quantidadeDiscos);

    printf("\n Movimentos: \n");
    hanoi(quantidadeDiscos, 1, 2, 3);
    printf("Torre resolvida!\n");

    return 0;
}


void hanoi(int n, int origem, int aux, int destino) {

    if (n > 0) {
        hanoi(n-1, origem, destino, aux);
        mover(origem, destino);
        hanoi(n-1, aux, origem, destino);
    }

}

void mover( int origem, int destino) {

    printf(" Mover disco da torre %d para %d\n", origem, destino);

}