#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_VERTICES 100
int minDistance(int dist[], bool visited[], int vertices) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < vertices; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}
void printSolution(int dist[], int vertices) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < vertices; i++)
        printf("%d \t %d\n", i, dist[i]);
}
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int start) {
    int dist[MAX_VERTICES];
    bool visited[MAX_VERTICES];
    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[start] = 0;
    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, visited, vertices);
        visited[u] = true;
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    printSolution(dist, vertices);
}
int main() {
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int startVertex;
    printf("Enter the starting vertex for Dijkstra's algorithm: ");
    scanf("%d", &startVertex);
    dijkstra(graph, vertices, startVertex);
    return 0;
}
