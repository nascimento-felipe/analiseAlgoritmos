# Complexidade de Tempo: Resumido

## Índice
 - [Introdução](#introdução)
 - [Modelo Computacional](#modelo-computacional)
 - [Conceitos e Nomenclaturas](#conceitos-e-nomeclaturas)
 - [Conclusão](#conclusão)

## Introdução

Todos os algoritmos do mundo, sem exceção, precisam de um determinado número de instruções para serem executados. Por exemplo: uma instrução _for(i = 0; i < 10; i++)_ vai rodar o que está em seu escopo 10 vezes.

Dentro desse escopo está um número específico de instruções que serão repetidas 10 vezes. Isso significa que, caso tivermos uma alocação de valor para alguma variável dentro desse _for_, serão ($10 ~ \cdot$ _valor\_de\_alocação\_ de\_memória_) instruções para o computador chegar ao fim da execução do programa.

```c:
    int x;

    for (int i = 0; i < 10; i++) {

        x = i; // essa linha vai rodar 10 vezes.
    
    }
```

Sendo assim, podemos estabelecer uma quantidade de instruções que são rodadas no nosso algoritmo, tentando prever assim o tempo¹ que nosso algoritmo deverá levar para terminar sua execução e, além disso, poderemos comparar o nosso algoritmo com outros algoritmos, procurando por pontos de melhorias.

> 1 - Esse tempo será baseado no nosso modelo, que será explicado no próximo tópico. 

Para isso, precisamos definir alguns conceitos e outros pontos que serão utilizados com exaustão na parte teórica e matemática dessa área.

Primeiro, será explicado o Modelo Computacional usado.

## Modelo Computacional

Como estou seguindo a disciplina que tive, vamos usar o Modelo Computacional Genérico com a Arquitetura de Von Neumann. Nesse modelo, temos: 
    
 - Operações sequenciais, acontecendo uma após a outra e nunca ao mesmo tempo;
 - Único processador;
 - Realiza as seguintes instruções: 
     - Aritméticas (soma, subtração, multiplicação, divisão, resto, piso e teto);
     - Movimentação de dados (carregar, armazenar e copiar);
     - Controle (desvio condicional e incondicional, chamada e retorno de rotinas).

Todas essas instruções têm tempo de execução constante, mesmo que tenham diferenças.

Por conta da diferença de cada computador existente no mundo, não será definido um tempo de execução para cada instrução; só usaremos a __quantidade total de instruções__ como base para comparação de algoritmos.

Caso você queira fazer uma comparação de tempo mais específica, é só definir um valor de tempo para cada instrução que você terá a quantidade de tempo para o algoritmo executar.

> Definindo cada instrução como $10^{-9}$ segundos, podemos ter uma base para quanto tempo determinado algoritmo levará para terminar sua execução. $\newline$ Esse tempo fica à seu critério :p

Definido nosso Modelo Computacional, serão apresentados alguns termos mais práticos que serão usados para descrever o comportamento dos algoritmos.

## Conceitos e Nomeclaturas

Podemos usar conceitos da área que auxiliarão na definição dos casos em que nossos algoritmos podem se encaixar. 

Todos nossos algoritmos recebem __parâmetros de entrada__ e executarão determinada tarefa baseados nessa entrada. Tomando por exemplo um algoritmo de multiplicação de matrizes: o algoritmo vai rodar N instruções, onde N é um valor variável que vai depender do tamanho das matrizes à serem multiplicadas. 

Você demora o mesmo tempo para multiplicar duas matrizes 3x3 e duas matrizes 100x100? É a mesma lógica com computadores.

Sendo assim, para complexidade de tempo, usaremos os seguintes termos:
 - __Pior Caso__, quando teremos a maior quantidade de instruções para serem executadas, geralmente acontece quando a entrada do algoritmo dificulta a execução da lógica interna;
 - __Melhor caso__, quando a entrada auxilia a lógica de execução do algoritmo e, dessa forma, o algoritmo rodará com a menor quantidade possível de tempo para essa lógica;
 - __Caso Médio__, que acontece quando nosso algoritmo terá uma entrada aleatória e executará uma quantidade de instruções que estará na média do nosso algoritmo. É o caso que mais aparece, já que dificilmente todas as entradas do algoritmo serão as piores possíveis ou melhores possíveis sempre que rodar.

## Conclusão