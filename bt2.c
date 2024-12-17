#include <stdio.h>
#include <stdlib.h>

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

void addEdge(int start, int end) {
    adjacencyMatrix[start][end] = 1;
    adjacencyMatrix[end][start] = 1;
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

int main() {
    initializeGraph();

    printf("Nhap so luong dinh: ");
    scanf("%d", &numVertices);

    int numEdges;
    printf("Nhap so luong canh: ");
    scanf("%d", &numEdges);

    printf("Nhap cac canh (dinh1 dinh2):\n");
    for (int i = 0; i < numEdges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(start, end);
    }

    displayMatrix();

}
