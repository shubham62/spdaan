#include <stdio.h>
#include <stdlib.h>

int bellmanFord(int distMat[20][20], int V, int E, int edge[20][2])
{
    int i,u,v,k,distance[20],parent[20],S,flag=1;
    
    for(i = 0; i < V; i++)
    {
    	distance[i] = 1000, parent[i] = -1;
    }
    printf("Enter source vertex: ");
    scanf("%d",&S);
    distance[S-1]=0;
        
    for(i = 0; i < V - 1; i++)
    {
        for(k = 0; k < E; k++)
        {
            u = edge[k][0], v = edge[k][1];
            if(distance[u] + distMat[u][v] < distance[v])
            {
                distance[v] = distance[u] + distMat[u][v] , parent[v]=u ;
            }
        }
    }

    for(k = 0; k < E; k++)
    {
        u = edge[k][0] , v = edge[k][1] ;
        if(distance[u]+distMat[u][v] < distance[v])
        flag = 0 ;
    }
    if(flag)
    {
    	for(i=0;i<V;i++)
    	{
            printf("Vertex %d -> cost = %d parent = %d\n",i+1,distance[i],parent[i]+1);
    	}
    }
    return flag;
}

int main()
{
    int V , edge[20][2], distMat[20][20], i, j, k = 0;
    printf("Enter no. of vertices: ");
    scanf("%d",&V);

    printf("Enter graph in matrix form:\n");
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            scanf("%d",&distMat[i][j]);
            if(distMat[i][j]!=0)
            {
                edge[k][0]=i,edge[k++][1]=j;
            }
        }
    }

    if(bellmanFord(distMat,V,k,edge))
    {
        printf("\nNo negative weight cycle\n");
    }
    else
    {
     	printf("\nNegative weight cycle exists\n");
    }
    return 0;
}