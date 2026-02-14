#include <stdio.h>
#define MAX 20
#define INF 9999

int main() {
    int n, cost[MAX][MAX], visited[MAX]={0};
    int i, j, min, u, v, ne=1, mincost=0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++) {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=INF;
        }

    visited[0]=1;

    printf("\nEdges in MST:\n");

    while(ne < n) {
        min = INF;

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(cost[i][j] < min)
                    if(visited[i] && !visited[j]) {
                        min = cost[i][j];
                        u=i;
                        v=j;
                    }

        printf("%d -- %d == %d\n",u,v,min);
        mincost += min;
        visited[v]=1;
        ne++;
    }

    printf("Total MST cost = %d\n",mincost);
    return 0;
}
