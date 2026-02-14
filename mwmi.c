#include <stdio.h>

#define MAX 20

int main() {
    int n, i, j;
    int weight[MAX];
    int adj[MAX][MAX];
    int selected[MAX] = {0};
    int chosen[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter weights of vertices:\n");
    for(i=0;i<n;i++)
        scanf("%d", &weight[i]);

    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d", &adj[i][j]);

    // Greedy selection
    for(i=0;i<n;i++) {
        int max = -1, index = -1;

        for(j=0;j<n;j++)
            if(!selected[j] && weight[j] > max) {
                max = weight[j];
                index = j;
            }

        if(index == -1) break;

        chosen[index] = 1;
        selected[index] = 1;

        // mark adjacent vertices as unavailable
        for(j=0;j<n;j++)
            if(adj[index][j])
                selected[j] = 1;
    }

    printf("\nSelected vertices in Independent Set:\n");
    for(i=0;i<n;i++)
        if(chosen[i])
            printf("Vertex %d (weight %d)\n", i, weight[i]);

    return 0;
}
