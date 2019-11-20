#include <iostream>
#include <stdio.h>
#include <omp.h>

using namespace std;

int Pits(double recorrido, double distancia, double pits, int gas[])
{

    double contDistancia = 0.0; //Contador de distancia
    int alfa = 0.0;          //contador A
    int beta = 0.0;          //contador B

    while (contDistancia < recorrido)
    {

        if (alfa < pits && gas[beta] <= (contDistancia + distancia))
        {
            contDistancia = gas[beta];
            beta++;
        } //fin loop if en la que se suma la distancia recorrida
        else
        {
            contDistancia += distancia;
        }

        if (contDistancia < recorrido)
        {
            contDistancia++;
        }

    } //fin while

    cout << "Deberá detenerse " << contDistancia << " veces" << endl;

    return 0;
};