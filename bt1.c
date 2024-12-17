#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
int numVertices = 0;

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjacencyList[MAX_VERTICES];

void initializeGraph() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        adjacencyList[i] = NULL;
        for (int j = 0; j < MAX_VERTICES; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
}

void addVertex() {
    numVertices++;
}

void addEdgeMatrix(int start, int end, int isDirected) {
    adjacencyMatrix[start][end] = 1;
    if (!isDirected) {
        adjacencyMatrix[end][start] = 1;
    }
}

void addEdgeList(int start, int end, int isDirected) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = end;
    newNode->next = adjacencyList[start];
    adjacencyList[start] = newNode;

    if (!isDirected) {
        newNode = (Node*)malloc(sizeof(Node));
        newNode->vertex = start;
        newNode->next = adjacencyList[end];
        adjacencyList[end] = newNode;
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

void displayList() {
    printf("Danh sach ke:\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d: ", i);
        Node* temp = adjacencyList[i];
        while (temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    initializeGraph();

    int isDirected, choice;
    printf("Do thi co huong? (1: Co, 0: Khong): ");
    scanf("%d", &isDirected);

    while (1) {
        printf("\n1. Them dinh\n2. Them canh\n3. Hien thi ma tran ke\n4. Hien thi danh sach ke\n5. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addVertex();
        } else if (choice == 2) {
            int start, end;
            printf("Nhap canh (start end): ");
            scanf("%d %d", &start, &end);
            addEdgeMatrix(start, end, isDirected);
            addEdgeList(start, end, isDirected);
        } else if (choice == 3) {
            displayMatrix();
        } else if (choice == 4) {
            displayList();
        } else if (choice == 5) {
            break;
        } else {
            printf("Lua chon khong hop le!\n");
        }
    }

}
