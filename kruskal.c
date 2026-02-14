#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct Edge {
    int u, v, weight;
};

struct Edge edges[MAX];
int parent[MAX];

int find(int i) {
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int i, int j) {
    parent[i] = j;
}

int compare(const void *a, const void *b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

int main() {
    int n, e, i, count = 0;
    int minCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");
    for(i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);

    for(i = 0; i < n; i++)
        parent[i] = i;

    qsort(edges, e, sizeof(edges[0]), compare);

    printf("\nEdges in MST:\n");

    for(i = 0; i < e && count < n-1; i++) {
        int uRoot = find(edges[i].u);
        int vRoot = find(edges[i].v);

        if(uRoot != vRoot) {
            printf("%d -- %d == %d\n", edges[i].u, edges[i].v, edges[i].weight);
            minCost += edges[i].weight;
            unionSet(uRoot, vRoot);
            count++;
        }
    }

    printf("Total MST cost = %d\n", minCost);
    return 0;
}
