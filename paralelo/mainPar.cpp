#include <iostream>
#include <stdio.h>
#include <chrono>
#include <omp.h>
#include "pitsPar.hpp"
#include <iostream>
#include <cmath>
#include <cfenv>
#include <climits>

#pragma STDC FENV_ACCESS ON

using namespace std::chrono;
using namespace std;

int main()
{

    double pista;    //distancia total de la pista
    double vueltas;  //cantidad de vueltas que se realizarán
    double proxPits; //distancia que puede recorrer entre paradas
    int paradas;     //cantidad de veces en las que deberá parar
    bool orden = true;
    int pistaOr;
    int i;
    long t_inicial = 0, t_final = 0;


    (double)pistaOr;

    cout << "Inserta la cantidad de vueltas que se realizarán" << endl;
    cin >> vueltas;
    cout << "\n";

    cout << "Inserta el tamaño de la pista." << '\n';
    cin >> pista;
    cout << '\n';

    pistaOr = pista;
    pista = pista * vueltas;

    (int)pistaOr;

    pistaOr = std::round(pistaOr);

    cout << "Recorrido total: " << pista << " km.\n"
         << endl;

    cout << "Del 1 al 100, 100 siendo como nuevas, cual es el desgaste de las llantas?" << '\n';
    cin >> proxPits;
    cout << '\n';

    cout << "Cuántas veces debería de parar el coche en los pits?" << endl;
    cin >> paradas;
    cout << "\n";

    int entradaPits[paradas]; //distancia a recorrer para la siguiente vuelta una vez que se ingresa a los pits
    int salidaPits[paradas];  //distancia a recorrer una vez que se sale de los pits para la siguiente vuelta

    #pragma omp parallel for private(i)
    for (i = 0; i < pistaOr; i++)
    {
        salidaPits[i] = 0;
    }

    #pragma omp critical
    while (orden)
    {
        cout << "Entra al while" << endl;

        Randomizador(paradas, entradaPits, pistaOr);
        OrdenParadas(entradaPits, paradas);

        if (entradaPits[0] <= proxPits)
        {
            cout << "Entra al if" << endl;
            orden = false;
        }
    }

    cout << "Los datos insertados son los siguientes: \n"
         << "Tamaño de la pista: " << pistaOr << " km.\n"
         << "Vueltas que debe dar: " << vueltas << "\n"
         << "El porcentaje de desgaste de las llantas insertado es de: " << proxPits << "%.\n"
         << "Paradas por realizar: " << paradas << "\n"
         << endl;

    auto start = high_resolution_clock::now();


    #pragma omp critical
    Pits(pista, proxPits, paradas, entradaPits);

    auto stop = high_resolution_clock::now();

    auto durationSeg = duration_cast<seconds>(stop - start);
    auto durationMilli = duration_cast<milliseconds>(stop - start);
    auto durationMicro = duration_cast<microseconds>(stop - start);

    cout << "Le tomo " << durationSeg.count() << " segundos\n";
    cout << "Le tomo " << durationMilli.count() << " milisegundos\n";
    cout << "Le tomo " << durationMicro.count() << " microsegundos\n";

    return 0;
}
