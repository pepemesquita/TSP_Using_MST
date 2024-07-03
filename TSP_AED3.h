#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>

int V;

int FindMinKey(int key[], bool mstSet[]) {
    int min = INT_MAX, minIndex;
    for (int vertex = 0; vertex < V; vertex++) {
        if (!mstSet[vertex] && key[vertex] < min) {
            min = key[vertex];
            minIndex = vertex;
        }
    }
    return minIndex;
}

void Prim(int** graph, int parent[]) {
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int currentVertex = FindMinKey(key, mstSet);
        mstSet[currentVertex] = true;

        for (int adjacentVertex = 0; adjacentVertex < V; adjacentVertex++) {
            if (graph[currentVertex][adjacentVertex] && !mstSet[adjacentVertex] && graph[currentVertex][adjacentVertex] < key[adjacentVertex]) {
                parent[adjacentVertex] = currentVertex;
                key[adjacentVertex] = graph[currentVertex][adjacentVertex];
            }
        }
    }
}

void PreorderTraversal(int parent[], int currentVertex, bool visited[], int cycle[], int *index) {
    visited[currentVertex] = true;
    cycle[(*index)++] = currentVertex;

    for (int adjacentVertex = 0; adjacentVertex < V; adjacentVertex++) {
        if (parent[adjacentVertex] == currentVertex && !visited[adjacentVertex]) {
            PreorderTraversal(parent, adjacentVertex, visited, cycle, index);
        }
    }
}

void Approximation(int** graph) {
    int parent[V];
    int root = 0;

    Prim(graph, parent);

    int cycle[V+1];
    bool visited[V];
    for (int i = 0; i < V; i++) visited[i] = false;

    int index = 0;
    PreorderTraversal(parent, root, visited, cycle, &index);
    cycle[index] = root;

    int cost = 0;
    for (int i = 0; i < V; i++) {
        cost += graph[cycle[i]][cycle[i+1]];
    }

    printf("Approximate path found: ");
    for (int i = 0; i <= V; i++) {
        printf("%d -> ", cycle[i]);
    }
    printf("\n");

    printf("Approximate path cost: %d\n", cost);
}
