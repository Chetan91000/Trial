
#include <stdio.h>
#define INF 99999 
struct Edge {
 int u, v, w;
};

void bellmanFord(struct Edge edges[], int V, int E, int src) {
 int dist[V];
 
 
 for (int i = 0; i < V; i++)
 dist[i] = INF;
 dist[src] = 0; 
 for (int i = 0; i < V - 1; i++) {
 for (int j = 0; j < E; j++) {
 int u = edges[j].u;
 int v = edges[j].v;
 int w = edges[j].w;
 if (dist[u] != INF && dist[u] + w < dist[v])
 dist[v] = dist[u] + w;
 }
 }
 for (int j = 0; j < E; j++) {
 int u = edges[j].u;
 int v = edges[j].v;
 int w = edges[j].w;
 if (dist[u] != INF && dist[u] + w < dist[v]) {
 printf("Graph contains a negative weight cycle!\n");
 return;
 }
 }
 printf("Vertex \t Distance from Source\n");
 for (int i = 0; i < V; i++)
 printf("%d \t %d\n", i, dist[i]);
}
int main() {
 int V = 4; 
int E = 5; 
 struct Edge edges[] = {
 {0, 1, 5},
 {0, 2, 4},
 {1, 3, 3},
 {2, 1, 6},
 {3, 2, 2}
 };
 int source = 0; 
 bellmanFord(edges, V, E, source);
 return 0;
}

