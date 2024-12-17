#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
int numVertices = 0;

void initializeGraph() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(int start, int end, int isDirected) {
    adjacencyMatrix[start][end] = 1;
    if (!isDirected) {
        adjacencyMatrix[end][start] = 1; 
    }
}

void displayMatrix() {
    printf("Ma tran ke:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

bool dfsDirected(int vertex, bool visited[], bool recStack[]) {
    visited[vertex] = true;
    recStack[vertex] = true;

    for (int i = 0; i < numVertices; i++) {
        if (adjacencyMatrix[vertex][i]) {
            if (!visited[i] && dfsDirected(i, visited, recStack)) {
                return true;
            } else if (recStack[i]) {
                return true;
            }
        }
    }

    recStack[vertex] = false;
    return false;
}

bool dfsUndirected(int vertex, bool visited[], int parent) {
    visited[vertex] = true;

    for (int i = 0; i < numVertices; i++) {
        if (adjacencyMatrix[vertex][i]) {
            if (!visited[i]) {
                if (dfsUndirected(i, visited, vertex)) {
                    return true;
                }
            } else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}

bool containsCycle(int isDirected) {
    bool visited[MAX_VERTICES] = {false};
    if (isDirected) {
        bool recStack[MAX_VERTICES] = {false};
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i] && dfsDirected(i, visited, recStack)) {
                return true;
            }
        }
    } else {
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i] && dfsUndirected(i, visited, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    initializeGraph();

    printf("Nhap so luong dinh: ");
    scanf("%d", &numVertices);

    int numEdges, isDirected;
    printf("Do thi co huong? (1: Co, 0: Khong): ");
    scanf("%d", &isDirected);

    printf("Nhap so luong canh: ");
    scanf("%d", &numEdges);

    printf("Nhap cac canh (dinh1 dinh2):\n");
    for (int i = 0; i < numEdges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(start, end, isDirected);
    }

    displayMatrix();

    if (containsCycle(isDirected)) {
        printf("Do thi co chu ky\n");
    } else {
        printf("Do thi khong co chu ky\n");
    }

}
