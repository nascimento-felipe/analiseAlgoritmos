# Análise de Algoritmos

## O que é esse repositório?

Esse repositório foi criado para armazenar algoritmos que são estudados durante minha disciplina de Análise de Algoritmos. A ideia é também misturar alguns algoritmos com estruturas de dados, que inclusive estão em um outro repositório aqui no meu perfil.

Essa segunda parte vai demorar um pouco, pois vou poder juntar os dois de forma eficiente somente no primeiro semestre de 2023, onde estudarei esses
assuntos de forma mais aprofundada.

Os Algoritmos que estudei têm propósitos variados, indo de buscas em um array de números inteiros até procurar o valor X da sequência de Fibonacci; porém
o conteúdo mais estudado durante toda a disciplina foram Algoritmos de Ordenação - só com números inteiros, por enquanto.

Sinta-se livre para estudar esses códigos :)

## Principais linguagens

Meu foco inicial é nas linguagens C, C++, Python e Java. Conforme meus trabalhos e provas forem terminando e o semestre chegando ao fim, terei mais tempo para fazer os código também em outras linguagens.

> OBS.: Na linguagem c++, não utilizei o "using namespace std" para ficar mais fácil para pessoas que não sabem c++ (eu agora, por exemplo) saberem quais funções são standard e saber como usar melhor esse namespace.

Todos os códigos em C e C++ tem comentários detalhados do que está sendo feito. Os demais terão comentários conforme eu tiver tempo, como já dito antes.

## Separação de pastas

Os algoritmos são separados por tipo, então caso queira procurar por um algoritmo de Merge Sort em Java, basta ir na pasta de "Merge Sort" e procurar pelo arquivo com a extensão ".java".

Dentro das pastas existe uma outra chamada "__executaveis__". Nela estão todos os arquivos compilados de C e C++. Os demais, oriundos de linguagens interpretadas, podem ser encontrados dentro da pasta com o nome do algoritmo.

## Pastas

Dê um passeio pelas pastas! :D

- Ordenação por Inserção:
    * [Insertion Sort](./algoritmos/Ordenacao/Insercao/Insertion_Sort/)
    * [Ordenação Binária](./algoritmos/Ordenacao/Insercao/Ordenacao_Binaria/)
    * [Shell Sort](./algoritmos/Ordenacao/Insercao/Shell_Sort/)

- Ordenação por Troca:
    * [Bubble Sort](./algoritmos/Ordenacao/Troca/Bubble_Sort/)
    * [Combo Sort](./algoritmos/Ordenacao/Troca/Combo_Sort/)
    * [Quick Sort](./algoritmos/Ordenacao/Troca/Quick_Sort/)
    * [Shake Sort](./algoritmos/Ordenacao/Troca/Shake_Sort/)

- Ordenação por Seleção:
    * [Selection Sort](./algoritmos/Ordenacao/Selecao/Selection_Sort/)
    * [Heap Sort](./algoritmos/Ordenacao/Selecao/Heap_Sort/)

- Outras lógicas de Ordenação:
    * [Merge Sort](./algoritmos/Ordenacao/Merge_Sort/)
    * [Radix Sort]()

- Exemplo de Grafo:
    * [Grafo](./algoritmos/Exemplo_Grafos/)

- Exemplo de Programação Dinâmica:
    * [Fibonacci Recursivo com Programação Dinâmica](./algoritmos/Programacao_Dinamica/)

- Algoritmos com outros propósitos:
    * [Fibonacci](./algoritmos/Propositos_Gerais/Fibonacci/)
    * [Torre de Hanoi](./algoritmos/Propositos_Gerais/TorreDeHanoi/)
    * [Busca Binária](./algoritmos/Propositos_Gerais/BuscaBinaria/)
    * [Máximo e Mínimo de um array](./algoritmos/Propositos_Gerais/MaxMin/)

[//]: # (colocar as pastas que faltaram - todos os das outras pastas.)
## Observações gerais

Não recomendo testar o fibonacci recursivo (que não é o de programação dinâmica), pois ele tem complexidade 2^n, que é bem ruim - pense em procurar o número 100 da série: seria 2^100 ou 1,2676506×(10^30). Ao invés disso, utilize o iterativo que tem O(n), ou seja, aumenta em mesma medida que n aumenta - se procurássemos pelo mesmo número 100 da série, teríamos uma complexidade de 100.

Porém, fique a vontade para testar e ver que realmente o retorno do programa é bem demorado, como era de se esperar.
