#include <stdio.h>

#define MAX 100

int main() {
    int n, i, j;
    int graph[MAX][MAX];
    int indegree[MAX] = {0};
    int queue[MAX], front = 0, rear = -1;
    int topo[MAX], count = 0;

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 1)
                indegree[j]++;
        }
    }

    // Insert vertices with indegree 0 into queue
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[++rear] = i;
    }

    // Kahn’s Algorithm
    while (front <= rear) {
        int u = queue[front++];
        topo[count++] = u;

        for (j = 0; j < n; j++) {
            if (graph[u][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0)
                    queue[++rear] = j;
            }
        }
    }

    // Validation
    if (count != n) {
        printf("\nGraph contains a cycle. Topological sorting not possible.\n");
    } else {
        printf("\nTopological Order:\n");
        for (i = 0; i < n; i++)
            printf("%d ", topo[i]);
        printf("\n");
    }

    return 0;
}