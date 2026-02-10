#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
int u, v, w;
} Edge;

Edge edges[MAX];
int parent[MAX];

int find(int i){
while(parent[i] != i)
i = parent[i];
return i;
}

void unionSet(int a, int b){
parent[a] = b;
}

int compare(const void *a, const void *b){
return ((Edge*)a)->w - ((Edge*)b)->w;
}

int main(){


int n, e;
printf("Enter vertices and edges: ");
scanf("%d %d",&n,&e);

for(int i=0;i<e;i++){
    scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);
}

for(int i=0;i<n;i++)
    parent[i]=i;

qsort(edges, e, sizeof(Edge), compare);

int count=0, cost=0;

printf("Edges in MST:\n");

for(int i=0;i<e && count<n-1;i++){

    int a=find(edges[i].u);
    int b=find(edges[i].v);

    if(a!=b){
        printf("%d - %d : %d\n",edges[i].u,edges[i].v,edges[i].w);
        cost+=edges[i].w;
        unionSet(a,b);
        count++;
    }
}

printf("Total cost = %d\n",cost);

}
