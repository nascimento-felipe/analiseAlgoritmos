#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void mergeSortTopDown(int* array, int n, int comeco, int fim);
void mergeSemSentinela(int* array, int n, int comeco, int meio, int fim);
void imprimirArray(int* array, int n, char* message);
void gerarArray(int* array, int n);

int* array = NULL;
int tamanho = 0;

int main(void) {

    printf("Merge Sort Recursivo Sem Sentinela na linguagem C\n\n");

    printf(" Digite o tamanho do array: ");
    scanf("%d", &tamanho);

// ---------------------------------------------------------------------------
    array = (int*) malloc(tamanho * sizeof(int));
//----------------------------------------------------------------------------

    gerarArray(array, tamanho);

    printf("Ordenacao\n");
    imprimirArray(array, tamanho, " Array desordenado:");
    mergeSortTopDown(array, tamanho, 0, tamanho - 1);
    imprimirArray(array, tamanho, "\n Array ordenado:");

    printf("\n\n");

    free(array);

    return 0;
}

void mergeSortTopDown(int* array, int n, int comeco, int fim) {
             
    // verifica se o array tem mais de 1 índice para poder dividir (Divide and Conquer)
    if (fim > comeco) {
        int meio = (comeco + fim) / 2;
        mergeSortTopDown(array, n, comeco, meio);
        mergeSortTopDown(array, n, meio+1, fim);
        mergeSemSentinela(array, n, comeco, meio, fim);
    }

}

void mergeSemSentinela(int* array, int n, int comeco, int meio, int fim) {

    // debug de comentário: array[8].

    int* arrayAuxiliar = (int*) malloc(n * sizeof(int));

    for (int i = 0; i <= meio; i++) {
        arrayAuxiliar[i] = array[i];
    }

    for (int j = meio+1; j <= fim; j++) {
        //            4 + 7 + 1 - 5 => 7
        //            4 + 7 + 1 - 6 => 6
        //            4 + 7 + 1 - 7 => 5
        //            4 + 7 + 1 - 8 ** NAO RODA ESSA ULTIMA VEZ PQ J == 8**
        arrayAuxiliar[meio+fim+1-j] = array[j];
    }

    int i = comeco;
    int j = fim;

    for (int k = comeco; k <= fim; k++) {
        if(arrayAuxiliar[i] <= arrayAuxiliar[j]) {
            array[k] = arrayAuxiliar[i];
            i++;
        } else {
            array[k] = arrayAuxiliar[j];
            j--;
        }
    }
    
    free(arrayAuxiliar);

}

void imprimirArray(int* array, int n, char* message) {

    printf("%s", message);

    for (int i = 0; i < n; i++) {
        printf(" %d", array[i]);
    }

}

void gerarArray(int* array, int n) {

    srand(time(0));
    for (int i = 0; i < n; i++) {
        array[i] = (rand() % 100) + 1;
    }

}