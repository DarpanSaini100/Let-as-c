#include <stdio.h>
#define MAX 100

int graph[MAX][MAX], transpose[MAX][MAX];
int visited[MAX], stack[MAX];
int top = -1;
int n;

void dfs1(int v) {
    visited[v] = 1;
    for(int i=0;i<n;i++) {
        if(graph[v][i] && !visited[i])
            dfs1(i);
    }
    stack[++top] = v;
}

void dfs2(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for(int i=0;i<n;i++) {
        if(transpose[v][i] && !visited[i])
            dfs2(i);
    }
}

void transposeGraph() {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            transpose[i][j] = graph[j][i];
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    // Step 1: fill stack by finish time
    for(int i=0;i<n;i++)
        if(!visited[i])
            dfs1(i);

    // Step 2: transpose graph
    transposeGraph();

    // reset visited
    for(int i=0;i<n;i++)
        visited[i] = 0;

    printf("\nStrongly Connected Components:\n");

    // Step 3: process stack
    while(top >= 0) {
        int v = stack[top--];
        if(!visited[v]) {
            printf("SCC: ");
            dfs2(v);
            printf("\n");
        }
    }

    return 0;
}
