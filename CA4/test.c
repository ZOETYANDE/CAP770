#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

typedef struct Graph {
    int V;
    Node** adjList;
} Graph;

// Function Definition
Node* createNode(int);
Graph* createGraph(int);
void addEdge(Graph*, int, int);
void dfsUtil(Graph*, int, int[]);
void dfs(Graph*, int);

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);

    printf("DFS traversal starting from vertex 0: ");
    dfs(graph, 0);
    printf("\n");


    return 0;
}

Node* createNode(int dest) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(0);
    }
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int V) {
    Graph* graph = malloc(sizeof(Graph));
    if (graph == NULL) {
        exit(0);
    }
    graph->V = V;
    graph->adjList = malloc(V * sizeof(Node*));
    if (graph->adjList == NULL) {
        exit(0);
    }

    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void dfsUtil(Graph* graph, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    Node* cr = graph->adjList[v];
    while (cr != NULL) {
        if (!visited[cr->dest]) {
            dfsUtil(graph, cr->dest, visited);
        }
        cr = cr->next;
    }
}

void dfs(Graph* graph, int startVertex) {
    int* visited = calloc(graph->V, sizeof(int));
    if (visited == NULL) {
        exit(0);
    }

    dfsUtil(graph, startVertex, visited);
    free(visited);
}