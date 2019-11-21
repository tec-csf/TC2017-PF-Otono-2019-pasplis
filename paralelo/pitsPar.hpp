#include <iostream>
#include <stdio.h>
#include <omp.h>

using namespace std;

int Randomizador(int paradas, int entradaPits[], int pistaOr)
{
    srand(time(NULL));

    #pragma omp for
    for (int i = 0; i < paradas; i++)
    {
        cout << i << "\n" << endl;
        entradaPits[i] = rand() % pistaOr;
    }
};

void AcomodaValores(int *var1, int *var2)
{
    int temporal = *var1;
    *var1 = *var2;
    *var2 = temporal;
};

void OrdenParadas(int entradaPits[], int paradas)
{

    int initium, finis;
    #pragma omp for
    for (initium = 0; initium < paradas; initium++)

        for (finis = 0; finis < (paradas - 1 - initium); finis++)
            if (entradaPits[finis] > entradaPits[finis - 1])
            {
                AcomodaValores(&entradaPits[finis], &entradaPits[finis + 1]);
            }
};

int Pits(double proxPits, double distancia, int paradas, int entradaPits[])
{

    double contDistancia = 0.0;
    double alfa = 0.0;
    int beta = 0;

    while (contDistancia < proxPits)
    {
        #pragma omp paradas if
        if (alfa < paradas && entradaPits[beta] <= (contDistancia + distancia))
        {
            contDistancia = entradaPits[beta];
            beta++;
        } 
        else
        {
            contDistancia += distancia;
        }
        if (contDistancia < proxPits)
        {
            alfa++;
        }
    }

    #pragma omp parallel if(alfa < 10)
    if (alfa < 10)
    {
        cout << "Las vueltas a recorrer son " << alfa << "."
             << endl;

        cout << "Puede pasar a los pits sin problema alguno.\n"
             << endl;
    }
    else
    #pragma omp parallel if (alfa >= 10)
    if (alfa >= 10)
    {
        cout << "Las vueltas a recorrer son " << alfa << "." <<endl;
        cout << "Le recomendamos cambiar las llantas INMEDIATAMENTE.\n"
             << endl;
    }

    return alfa;
};