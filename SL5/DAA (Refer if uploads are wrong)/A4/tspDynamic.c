#include<stdio.h>
#include <stdlib.h>
 
int distMat[10][10], completed[10], n, cost = 0;
 
void takeInput()
{
    int i,j;
 
    printf("Enter the number of cities: ");
    scanf("%d", &n);
 
    printf("\nEnter the Cost Matrix\n");
 
    for(i = 0; i < n; i++)
    {
        printf("\nEnter Elements of Row: %d\n", i+1);
 
        for( j = 0; j < n; j++)
        {
            scanf("%d", &distMat[i][j]);
        }
        completed[i] = 0;
    }
 
    printf("\n\nThe Cost Matrix is:");
 
    for(i = 0; i < n; i++)
    {
        printf("\n");
 
        for(j = 0;j < n;j++)
        {
            printf("%d\t",distMat[i][j]);
        }
    }
}

int least(int c)
{
    int i, nc = 999;
    int min = 999, kmin;
 
    for(i = 0; i < n; i++)
    {
        if((distMat[c][i] != 0)&&(completed[i] == 0))
        {
            if(distMat[c][i]+distMat[i][c] < min)
            {
                min = distMat[i][c]+distMat[c][i];
                kmin = distMat[c][i];
                nc = i;
            }
        }
    }
 
    if(min != 999)
    {
        cost += kmin;
    }
    return nc;
}
 
void mincost(int city)
{
    int i, ncity;
    completed[city] = 1;
 
    printf("%d--> ", city+1);
    ncity = least(city);
 
    if(ncity == 999)
    {
        ncity = 0;
        printf("%d",ncity+1);
        cost += distMat[city][ncity];
        return;
    }
    mincost(ncity);
}
 
int main()
{
    takeInput();
 
    printf("\n\nThe Path is:\n");
    mincost(0); //passing 0 because starting vertex
 
    printf("\n\nMinimum cost is %d\n ",cost);
 
    return 0;
}
