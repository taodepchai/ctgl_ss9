#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjacencyList[MAX_VERTICES];
bool visited[MAX_VERTICES];
int numVertices;

void initializeGraph() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        adjacencyList[i] = NULL;
        visited[i] = false;
    }
}

void addEdge(int start, int end) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = end;
    newNode->next = adjacencyList[start];
    adjacencyList[start] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = start;
    newNode->next = adjacencyList[end];
    adjacencyList[end] = newNode;
}

void displayAdjacencyList() {
    printf("Danh sach ke:\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d: ", i);
        Node* temp = adjacencyList[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void bfs(int startVertex) {
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("Thu tu duyet BFS: ");
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        Node* temp = adjacencyList[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
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

    displayAdjacencyList();

    int startVertex;
    printf("Nhap dinh bat dau duyet BFS: ");
    scanf("%d", &startVertex);

    bfs(startVertex);

}
