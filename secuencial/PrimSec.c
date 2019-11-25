#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define infinity 9999
#define MAX 20

int G[MAX][MAX], spanning[MAX][MAX], n;

int prims();

int main()
{
    clock_t t;

    int i, j, total_cost;
    printf("Cuántas paradas va a hacer?\n");
    scanf("%d", &n);

    printf("\nIngresa el numero de paradas:\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    t = clock();
    total_cost = prims();
    printf("\nLas paradas a hacer son:\n");

    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("%d --> %d\n", i+1, j+1);
            //printf("%d\t", spanning[i][j]);
    }
    t = clock() - t;

    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

    printf("El tiempo de ejecución es de: %f segundos\n", time_taken);

    printf("\n\nDistancia minima entre paradas = %d\n", total_cost);
    return 0;
}

int prims()
{
    int cost[MAX][MAX];
    int u, v, min_distance, distance[MAX], from[MAX];
    int visited[MAX], no_of_edges, i, min_cost, j;

    //create cost[][] matrix,spanning[][]
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (G[i][j] == 0)
                cost[i][j] = infinity;
            else
                cost[i][j] = G[i][j];
            spanning[i][j] = 0;
        }

    //initialise visited[],distance[] and from[]
    distance[0] = 0;
    visited[0] = 1;

    for (i = 1; i < n; i++)
    {
        distance[i] = cost[0][i];
        from[i] = 0;
        visited[i] = 0;
    }

    min_cost = 0;        //cost of spanning tree
    no_of_edges = n - 1; //no. of edges to be added

    while (no_of_edges > 0)
    {
        //find the vertex at minimum distance from the tree
        min_distance = infinity;
        for (i = 1; i < n; i++)
            if (visited[i] == 0 && distance[i] < min_distance)
            {
                v = i;
                min_distance = distance[i];
            }

        u = from[v];

        //insert the edge in spanning tree
        spanning[u][v] = distance[v];
        spanning[v][u] = distance[v];
        no_of_edges--;
        visited[v] = 1;

        //updated the distance[] array
        for (i = 1; i < n; i++)
            if (visited[i] == 0 && cost[i][v] < distance[i])
            {
                distance[i] = cost[i][v];
                from[i] = v;
            }

        min_cost = min_cost + cost[u][v];
    }

    return (min_cost);
}