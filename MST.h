#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int V;


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

void printPreorderTraversal(int parent[]) {
   
   printf("The preorder traversal of the tree is found to be ");
   
   for (int i = 1; i < V; i++) {
      printf("%d -> ", parent[i]);
   }
   printf("\n");
}

void tspApproximation(int** graph) {
   
   int parent[V];
   int root = 0;

   primMST(graph, parent);
   
   printPreorderTraversal(parent);
   
   printf("Adding the root node at the end of the traced path ");
   for (int i = 1; i < V; i++) {
      printf("%d -> ", parent[i]);
   }
   
   printf("%d -> %d\n", root, parent[1]);
   
   int cost = 0;
   for (int i = 1; i < V; i++) {
      cost += graph[parent[i]][i];
   }
   printf("Sum of all the costs in the minimum spanning tree is %d.\n", cost);
   
}
