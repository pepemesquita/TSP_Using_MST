# Algoritmo Aproximativo para o Problema do Caixeiro Viajante usando a Árvore Geradora Mínima de Prim

Este repositório contém uma implementação em C de um algoritmo aproximativo para resolver o Problema do Caixeiro Viajante (TSP) utilizando a Árvore Geradora Mínima (MST) de Prim.

## Descrição

O Problema do Caixeiro Viajante (TSP) é um problema clássico da teoria dos grafos e da otimização combinatória. O objetivo é encontrar o caminho mais curto que visita cada vértice exatamente uma vez e retorna ao vértice inicial.

Este código implementa uma solução aproximativa para o TSP baseada na construção de uma Árvore Geradora Mínima (MST) utilizando o algoritmo de Prim. A ideia é usar a MST para criar um ciclo Hamiltoniano aproximado através de uma travessia em pré-ordem.

## Estrutura do Código

- **FindMinKey**: Função auxiliar que encontra o vértice com a menor chave que ainda não foi incluído na MST.
- **Prim**: Implementação do algoritmo de Prim para construir a MST a partir de um grafo.
- **PreorderTraversal**: Função auxiliar que realiza a travessia em pré-ordem da MST para construir um ciclo Hamiltoniano aproximado.
- **Approximation**: Função principal que executa o algoritmo aproximativo para o TSP.

## Como Usar

1. **Compilação**: Compile o código usando um compilador C, como `gcc`.
   ```bash
   gcc -o tsp_approximation tsp_approximation.c
   ```

2. **Execução**: Execute o programa compilado + o arquivo que contém a matriz.
   ```bash
   ./tsp_approximation.exe ..\tsp1_253.txt
   ```

3. **Entrada**: O código espera um arquivo.txt representado por uma matriz de adjacência, onde `V` é o número de vértices.

4. **Saída**: O programa imprime o ciclo Hamiltoniano aproximado encontrado e o custo desse ciclo.

## Exemplo

Suponha que temos o seguinte grafo representado por uma matriz de adjacência:

```.txt
  0   29  20  21  16  31  100 12  4   31  18
  29  0   15  29  28  40  72  21  29  41  12
  20  15  0   15  14  25  81  9   23  27  13
  21  29  15  0   4   12  92  12  25  13  25
  16  28  14  4   0   16  94  9   20  16  22
  31  40  25  12  16  0   95  24  36  3   37
  100 72  81  92  94  95  0   90  101 99  84
  12  21  9   12  9   24  90  0   15  25  13
  4   29  23  25  20  36  101 15  0   35  18
  31  41  27  13  16  3   99  25  35  0   38
  18  12  13  25  22  37  84  13  18  38  0
```

A saída será:

```
Approximate path found: 0 -> 1 -> 3 -> 2 -> 0 -> 
Approximate path cost: 278
```

## Observações

- Este algoritmo fornece uma solução aproximada para o TSP, não a solução exata.
- A precisão da aproximação depende da estrutura do grafo.
