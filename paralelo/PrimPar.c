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

    int minDist;    

    int newElem;    

    prim.total_minDist = 0;
    prim.counts = 0;

    
    minDist = 1000;

   

    printf("A continuación, inserte la cantidad de paradas de su ruta:\n");
    scanf("%d", &prim.dim);

    int num = prim.dim;

    int id = omp_get_thread_num();

    srand(time(NULL));

    printf("Inserta el peso del tráfico: \n");

    printf("Hilo %d\n", id);

    for (i = 0; i < prim.dim; ++i)
    {
        for (j = 0; j < prim.dim; j++)
        {
            prim.edge[i][j] = rand() % num;

            printf("Cost: %d ",prim.edge[i][j]);
            printf("From %d To %d\n",i,j);
        }
    }


    double start = omp_get_wtime();
    init();

    for (k = 0; k < prim.dim - 1; k++)
    {
        minDist = 1000;

        for (i = 0; i < prim.counts; i++)
        {

#pragma omp parallel for schedule(static)
            for (j = 0; j < prim.dim; j++)
            {
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


    return 0;
}

void init(void)
{

    int i, j;

    prim.total_minDist = 0;
    prim.counts = 0;
    for (i = 0; i < prim.dim; i++)
        prim.U[i] = -1;

    prim.U[0] = 0;
    delete (prim.U[0]);
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