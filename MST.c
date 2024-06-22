#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MST.h"


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

    V = count; 
    printf("Amount of vertices: %d\n", V+1);

    fclose(f);

    f = fopen(fileName, "r");
    if (f == NULL) {
        perror("Error opening the file");
        return 1;
    }

    int** graph = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph[i] = (int*)malloc(V * sizeof(int));
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            fscanf(f, "%d ", &graph[i][j]);
        }
    }

    fclose(f);

    tspApproximation(graph);

    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);

    printf("Time:%f\n",(clock() - time) / (double)CLOCKS_PER_SEC);

    return 0;
}