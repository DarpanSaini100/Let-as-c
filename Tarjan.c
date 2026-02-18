#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX], disc[MAX], low[MAX];
int stack[MAX], inStack[MAX];
int top = -1;
int timeCounter = 0;
int n;

void push(int v) {
    stack[++top] = v;
    inStack[v] = 1;
}

int pop() {
    int v = stack[top--];
    inStack[v] = 0;
    return v;
}

void tarjanDFS(int u) {
    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;

    push(u);

    for(int v = 0; v < n; v++) {
        if(graph[u][v]) {
            if(!visited[v]) {
                tarjanDFS(v);
                if(low[v] < low[u])
                    low[u] = low[v];
            }
            else if(inStack[v]) {
                if(disc[v] < low[u])
                    low[u] = disc[v];
            }
        }
    }

    // root of SCC
    if(low[u] == disc[u]) {
        printf("SCC: ");
        while(1) {
            int v = pop();
            printf("%d ", v);
            if(v == u) break;
        }
        printf("\n");
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    for(int i=0;i<n;i++)
        if(!visited[i])
            tarjanDFS(i);

    return 0;
}
