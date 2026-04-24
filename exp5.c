#include <stdio.h>
int matrix[25][25], visited[25];
int n, cost = 0;
int least(int c)
{
    int i, nc = -1;
    int min = 999, kmin;
    for(i = 0; i < n; i++)
    {
        if(matrix[c][i] != 0 && visited[i] == 0)
        {
            if(matrix[c][i] < min)
            {
                min = matrix[c][i];
                kmin = matrix[c][i];
                nc = i;
            }
        }
    }
    if(nc != -1)
        cost += kmin;

    return nc;
}
void mincost(int city)
{
    int ncity;
    visited[city] = 1;
    printf("%d ", city + 1);
    ncity = least(city);
    if(ncity == -1)
    {
        ncity = 0;
        printf("%d", ncity + 1);
        cost += matrix[city][ncity];
        return;
    }
    mincost(ncity);
}
int main()
{
    int i, j;
    printf("Enter Total Number of Cities: ");
    scanf("%d", &n);
    printf("\nEnter Cost Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
        visited[i] = 0;
    }
    printf("\nPath: ");
    mincost(0);
    printf("\nMinimum Cost: %d\n", cost);
    return 0;
}
