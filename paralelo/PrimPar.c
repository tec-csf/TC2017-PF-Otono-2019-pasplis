/*
 *
 * Proyecto final
 * 
 * Daniel Roa       -   A01021960
 * Christian Dalma  -   A01423166  
 * 
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
// #include "PrimPar.h"

#define DIM 1000
void init(void);
void delete (int);

struct prims
{
    int edge[DIM][DIM];
    int dim;
    int U[DIM];
    int total_minDist;
    int counts;
};

struct prims prim;

int main()
{
    int ch, j, t, p_c, p_j, k, serial = 1, i;

    int minDist;    //variable that holds the current maximum distance

    int newElem;    //variable that holds the next node in MST int newElem;

    prim.total_minDist = 0;
    prim.counts = 0;

    //declaring the structs the are used by gettimeofday
    //struct timeval tb1;
    //struct timeval tb2;
    //setting the minimum distance
    minDist = 1000;

    //opterr = 0;
    //parsing the arguments given

    printf("A continuación, inserte la cantidad de paradas de su ruta:\n");
    scanf("%d", &prim.dim);

    printf("Inseta el peso del tráfico: \n");

    for (i = 0; i < prim.dim; ++i)
    {
        for (j = 0; j < prim.dim; j++)
        {
            scanf("%d", &(prim.edge[i][j]));
            printf("Cost: %d ",prim.edge[i][j]);
            printf("From %d To %d\n",i,j);
        }
    }

    //initializing the data

    double start = omp_get_wtime();
    init();


    //calculating for all the nodes
    for (k = 0; k < prim.dim - 1; k++)
    {
        minDist = 1000;

        for (i = 0; i < prim.counts; i++)
        {

#pragma omp parallel for schedule(dynamic)
            for (j = 0; j < prim.dim; j++)
            {
                //find the minimum weight
                if (prim.edge[prim.U[i]][j] > minDist || prim.edge[prim.U[i]][j] == 0)
                {
                    continue;
                }
                else
                {
#pragma omp critical
                    {
                        minDist = prim.edge[prim.U[i]][j];
                        newElem = j;
                        printf("%d --> %d\n", i + 1, j + 1);
                    }
                }
            }
        }
        prim.total_minDist += minDist;
        prim.U[i] = newElem;
        delete (newElem);
        
        prim.counts++;
    }

    printf("\n");
    
    for (i = 0; i < prim.dim; i++)
    {
        printf("%d ", prim.U[i] + 1);
        if (i < prim.dim - 1)
            printf("-> ");
    }
    printf("\n\n");

    double finito = omp_get_wtime() - start;

    printf("Le tomó %.5g segundos en averiguar una solución.\n", finito);

    printf("Distancia mínima entre paradas: %d\n\n", prim.total_minDist);
    //printf("\nProgram terminates now..\n");


    return 0;
}

void init(void)
{

    int i, j;

    prim.total_minDist = 0;
    prim.counts = 0;

    //initializing the U set
    for (i = 0; i < prim.dim; i++)
        prim.U[i] = -1;

    //storing the first node into the U set
    prim.U[0] = 0;
    //deleting the first node
    delete (prim.U[0]);
    //incrementing by one the number of node that are inside the U set
    prim.counts++;
}

void delete (int next_element)
{

    int k;
    for (k = 0; k < prim.dim; k++)
    {
        prim.edge[k][next_element] = 0;
    }
}