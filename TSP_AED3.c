#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TSP_AED3.h"



int main(int argc, char *argv[]) {
    clock_t time;
    time = clock();
    char c;
    int count = 0;

    if (argc < 2) {
        fprintf(stderr, "Use: %s <file_name>\n", argv[0]);
        return 1;
    }

    char *fileName = argv[1];

    FILE *f = fopen(fileName, "r");
    if (f == NULL) {
        perror("Error opening the file");
        return 1;
    }

    while ((c = getc(f)) != EOF) {
        if (c == '\n') {
            count++;
        }
    }

    V = count + 1; 
    printf("Quantidade de vértices: %d\n", V);

    fclose(f);

    f = fopen(fileName, "r");
    if (f == NULL) {
        perror("Error opening the file");
        return 1;
    }

    // Matrix allocated 
    int** graph = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph[i] = (int*)malloc(V * sizeof(int));
    }

    // Read graphs
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            fscanf(f, "%d ", &graph[i][j]);
        }
    }

    fclose(f);

    // Execute the main algorithm
    tspApproximation(graph);

    // Free memory alloced
    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);

    printf("Tempo de execução: %f segundos\n", (clock() - time) / (double)CLOCKS_PER_SEC);

    return 0;
}
