#include <chrono>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include "pitsSec.hpp"

using namespace std::chrono;
using namespace std;

int main()
{

    double pista;    //distancia total de la pista
    double vueltas;  //cantidad de vueltas que se realizarán
    double proxPits; //distancia que puede recorrer entre paradas
    int paradas;     //cantidad de veces en las que deberá parar
    bool orden = true;
    double pistaOr;
    int i;

    cout << "Inserta la cantidad de vueltas que se realizarán" << endl;
    cin >> vueltas;
    cout << "\n";

    cout << "Inserta el tamaño de la pista." << '\n';
    cin >> pista;
    cout << '\n';

    double pistaDouble = pista;

    pistaOr = pista;
    pista = pista * vueltas;

    (int)pistaOr;
    pistaOr = (std::round(pistaOr));

    cout << "Recorrido de una vuelta " << pistaOr << endl;

    cout << "Recorrido total: " << pista << " km.\n"
         << endl;

    cout << "Del 1 al 100, cuál sería el porcentaje de desgaste?" << '\n';
    cin >> proxPits;
    cout << '\n';

    cout << "Cuántas veces debería de parar el coche en los pits?" << endl;
    cin >> paradas;
    cout << "\n";

    cout << "De preferencia pare a cambiar sus neumáticos.\n"
         << endl;

    int entradaPits[paradas]; //distancia a recorrer para la siguiente vuelta una vez que se ingresa a los pits
    int salidaPits[paradas];  //distancia a recorrer una vez que se sale de los pits para la siguiente vuelta

    for (i = 0; i < pistaOr; i++)
    {
        //cout << "Entrada #" << i << " al for." << endl;
        salidaPits[i] = 0;
    }

    //(int)vueltas;

    while (orden)
    {
        Randomizador(paradas, entradaPits, pistaOr);
        OrdenParadas(entradaPits, paradas);

        if (entradaPits[0] <= proxPits)
        {
            orden = false;
        }
    }

    cout << "Los datos insertados son los siguientes: \n"
         << "Tamaño de la pista: " << pistaDouble << " km.\n"
         << "Vueltas que debe dar: " << vueltas << "\n"
         << "El porcentaje de desgaste de las llantas es de: " << proxPits << "%.\n"
         << "Paradas por realizar: " << paradas << "\n"
         << endl;

    auto start = high_resolution_clock::now();

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