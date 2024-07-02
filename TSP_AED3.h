#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int V;

// Find the vertex with the min key 
int findMinKey(int key[], bool mstSet[]) {
   int min = INT_MAX, minIndex;
   for (int v = 0; v < V; v++) {
      if (!mstSet[v] && key[v] < min) {
         min = key[v];
         minIndex = v;
      }
   }
   return minIndex;
}

// Prim algorithm to build mst
void primMST(int** graph, int parent[]) {
   int key[V]; 
   bool mstSet[V];
   
   for (int i = 0; i < V; i++) {
      key[i] = INT_MAX;
      mstSet[i] = false;
   }

   key[0] = 0;
   parent[0] = -1;

   for (int count = 0; count < V - 1; count++) {   
      int u = findMinKey(key, mstSet);
      mstSet[u] = true;

      for (int v = 0; v < V; v++) {
         if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
            parent[v] = u;
            key[v] = graph[u][v];
         }
      }
   }
}

// Auxiliar function to build the preoder 
void preorderTraversal(int parent[], int u, bool visited[], int cycle[], int *index) {
   visited[u] = true;
   cycle[(*index)++] = u;

   for (int v = 0; v < V; v++) {
      if (parent[v] == u && !visited[v]) {
         preorderTraversal(parent, v, visited, cycle, index);
      }
   }
}

void tspApproximation(int** graph) {
    int parent[V];
    int root = 0;

    primMST(graph, parent);

    // Transforming the MST into a hamiltonian cycle
    int cycle[V+1];  // +1 to include the return at start
    bool visited[V];
    for (int i = 0; i < V; i++) visited[i] = false;

    int index = 0;
    preorderTraversal(parent, root, visited, cycle, &index);
    cycle[index] = root; 

    // Calculating the cost of cycle
    int cost = 0;
    for (int i = 0; i < V; i++) {
        cost += graph[cycle[i]][cycle[i+1]];
    }

    printf("Caminho aproximado encontrado: ");
    for (int i = 0; i <= V; i++) {
        printf("%d -> ", cycle[i]);
    }
    printf("\n");

    printf("Custo aproximado do caminho encontrado: %d\n", cost);
}