#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void DepthFirstSearch(int** graph, int vertexes, int startVertex) {
    int* visited = (int*)malloc(sizeof(int) * vertexes);
    int* stack = (int*)malloc(sizeof(int) * vertexes);
    int top = -1;

    if (visited == NULL || stack == NULL) {
        printf("Ошибка выделения памяти.\n");
        return;
    }

    for (int i = 0; i < vertexes; i++) {
        visited[i] = 0;
    }

    stack[++top] = startVertex;
    visited[startVertex] = 1;

    printf("DFS начиная с вершины %d: ", startVertex + 1);

    while (top >= 0) {
        int currentVertex = stack[top--];
        printf("%d ", currentVertex + 1);

        for (int i = 0; i < vertexes; i++) {
            if (graph[currentVertex][i] && !visited[i]) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");

    free(visited);
    free(stack);
}

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));

    int vertexNum;
    printf("Введите количество вершин графа: ");
    scanf("%d", &vertexNum);

    int** adjacencyMatrix = (int**)malloc(sizeof(int*) * vertexNum);

    if (adjacencyMatrix == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }

    for (int i = 0; i < vertexNum; i++) {
        adjacencyMatrix[i] = (int*)malloc(sizeof(int) * vertexNum);
        if (adjacencyMatrix[i] == NULL) {
            printf("Ошибка выделения памяти.\n");
            return 1;
        }
    }

    for (int i = 0; i < vertexNum; i++) {
        for (int j = 0; j < vertexNum; j++) {
            adjacencyMatrix[i][j] = (i != j) ? (rand() % 2) : 0;
        }
    }

    printf("\nМатрица смежности:\n");
    for (int i = 0; i < vertexNum; i++) {
        for (int j = 0; j < vertexNum; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    DepthFirstSearch(adjacencyMatrix, vertexNum, 0);

    for (int i = 0; i < vertexNum; i++) {
        free(adjacencyMatrix[i]);
    }
    free(adjacencyMatrix);

    return 0;
}
