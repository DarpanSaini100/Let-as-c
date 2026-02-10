#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int distance[MAX];
int queue[MAX];

int main(){


int n, edges, u, v, start;
int front=0, rear=0;

printf("Enter number of vertices: ");
scanf("%d",&n);

printf("Enter number of edges: ");
scanf("%d",&edges);

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        graph[i][j]=0;
    }
}

printf("Enter edges (u v):\n");
for(int i=0;i<edges;i++){
    scanf("%d %d",&u,&v);
    graph[u][v]=1;
    graph[v][u]=1; // undirected
}

printf("Enter starting vertex: ");
scanf("%d",&start);

for(int i=0;i<n;i++){
    visited[i]=0;
    distance[i]=-1;
}

visited[start]=1;
distance[start]=0;

queue[rear++]=start;

while(front<rear){

    int curr=queue[front++];

    for(int i=0;i<n;i++){
        if(graph[curr][i] && !visited[i]){
            visited[i]=1;
            distance[i]=distance[curr]+1;
            queue[rear++]=i;
        }
    }
}

printf("\nShortest distances from node %d:\n",start);

for(int i=0;i<n;i++){
    printf("To %d -> %d edges\n",i,distance[i]);
}

}
