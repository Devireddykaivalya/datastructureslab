#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_VERTICES 100
struct Edge {
    int src, dest, weight;
};
struct Graph {
    int vertices, edges;
    struct Edge* edge;
};
struct Graph* createGraph(int vertices, int edges) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->edges = edges;
    graph->edge = (struct Edge*)malloc(edges * sizeof(struct Edge));
    return graph;
}
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}
void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}
int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}
void kruskalMST(struct Graph* graph) {
    int vertices = graph->vertices;
    struct Edge result[vertices];
    int e = 0;
    int i = 0;
    qsort(graph->edge, graph->edges, sizeof(graph->edge[0]), compare);
    int parent[vertices];
    for (int v = 0; v < vertices; v++)
        parent[v] = -1;
    while (e < vertices - 1 && i < graph->edges) {
        struct Edge next_edge = graph->edge[i++];
        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);
        if (x != y) {
            result[e++] = next_edge;
            Union(parent, x, y);
        }
    }
    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++)
        printf("%d - %d: %d\n", result[i].src, result[i].dest, result[i].weight);
}
int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    struct Graph* graph = createGraph(vertices, edges);
    printf("Enter the edges and weights (src dest weight):\n");
    for (int i = 0; i < edges; i++)
        scanf("%d %d %d", &graph->edge[i].src, &graph->edge[i].dest, &graph->edge[i].weight);
    kruskalMST(graph);
    return 0;
}
