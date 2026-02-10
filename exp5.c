#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX], transpose[MAX][MAX];
int visited[MAX];
int stack[MAX], top = -1;
int n;

// DFS to fill stack
void dfs1(int v) {
visited[v] = 1;


for(int i = 0; i < n; i++) {
    if(graph[v][i] && !visited[i]) {
        dfs1(i);
    }
}

stack[++top] = v;


}

// DFS on transposed graph
void dfs2(int v) {
visited[v] = 1;
printf("%d ", v);


for(int i = 0; i < n; i++) {
    if(transpose[v][i] && !visited[i]) {
        dfs2(i);
    }
}

}

int main() {

int edges, u, v;

printf("Enter number of vertices: ");
scanf("%d", &n);

printf("Enter number of edges: ");
scanf("%d", &edges);

// Initialize graphs
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        graph[i][j] = 0;
        transpose[i][j] = 0;
    }
}

printf("Enter edges (u v):\n");
for(int i=0;i<edges;i++){
    scanf("%d %d",&u,&v);
    graph[u][v] = 1;
    transpose[v][u] = 1; // reverse edge
}

// Step 1: DFS to fill stack
for(int i=0;i<n;i++){
    visited[i] = 0;
}

for(int i=0;i<n;i++){
    if(!visited[i]){
        dfs1(i);
    }
}

// Step 2: Reset visited
for(int i=0;i<n;i++){
    visited[i] = 0;
}

// Step 3: Process stack
printf("\nStrongly Connected Components are:\n");

while(top != -1){
    int node = stack[top--];

    if(!visited[node]){
        dfs2(node);
        printf("\n");
    }
}

return 0;

}
