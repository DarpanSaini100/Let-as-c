#include <stdio.h>

#define MAX 100
#define INF 9999

int main(){


int n, graph[MAX][MAX], visited[MAX]={0};
int dist[MAX];

printf("Enter number of vertices: ");
scanf("%d",&n);

printf("Enter adjacency matrix (0 for no edge):\n");

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        scanf("%d",&graph[i][j]);
        if(graph[i][j]==0 && i!=j)
            graph[i][j]=INF;
    }
}

int start;
printf("Enter starting vertex: ");
scanf("%d",&start);

for(int i=0;i<n;i++){
    dist[i]=INF;
}

dist[start]=0;

for(int count=0;count<n-1;count++){

    int min=INF, u;

    for(int i=0;i<n;i++){
        if(!visited[i] && dist[i]<min){
            min=dist[i];
            u=i;
        }
    }

    visited[u]=1;

    for(int v=0;v<n;v++){
        if(!visited[v] && graph[u][v]!=INF &&
           dist[u]+graph[u][v] < dist[v]){

            dist[v]=dist[u]+graph[u][v];
        }
    }
}

printf("\nShortest distances from node %d:\n",start);

for(int i=0;i<n;i++){
    printf("To %d -> %d\n",i,dist[i]);
}


}
