#include <iostream>
#include <stdio.h>
#include <omp.h>

using namespace std;

int PosiblesAccidentes(int paradas, int entradaPits[], int pistaOr)
{
    srand(time(NULL));

    int pistaRan = pistaOr*10;

    //cout << "pistaRan " << pistaRan << endl;

    for (int i = 0; i < paradas; i++)
    {
        entradaPits[i] = rand() % pistaRan;

        //cout << entradaPits[i] << endl;
    }
};

void AcomodaValores(int *var1, int *var2)
{
    int temporal = *var1;
    *var1 = *var2;
    *var2 = temporal;
};

void PosiblesParadas(int entradaPits[], int paradas)
{

    int initium, finis;

    #pragma omp parallel for
    for (initium = 0; initium < paradas; initium++)

        for (finis = 0; finis < (paradas - 1 - initium); finis++)
            if (entradaPits[finis] > entradaPits[finis - 1])
            {
                AcomodaValores(&entradaPits[finis], &entradaPits[finis + 1]);
            }
};

int Pits(double distancia, double proxPits, int paradas, int entradaPits[])
{

    double contDistancia = 0.0;
    double alfa = 0.0;
    int beta = 0;

    #pragma omp parallel
    {
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
    }

    cout << "Alfa es " << alfa << "\n" << endl;

    #pragma omp parallel
    (int)alfa;

    if (alfa < 10)
    {
        cout << "Las vueltas a recorrer son " << alfa;

        cout << ", por lo tanto, si puede pasar a los pits sin problema alguno.\n"
             << endl;
        }
        else if (alfa >= 10)
        {
            cout << "Las vueltas a recorrer son " << alfa;
            cout << "por lo tanto le recomendamos cambiar las llantas INMEDIATAMENTE.\n"
                << endl;
        }

    return alfa;
};