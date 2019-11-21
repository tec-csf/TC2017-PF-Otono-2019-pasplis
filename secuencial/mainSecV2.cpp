#include <chrono>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include "pitsSec.hpp"

using namespace std::chrono;
using namespace std;

int OptLluvia(double pista, int lluvia, int paradas, double pistaOr, double vueltas, int* entradaPits, int* salidaPits){

    double pistaDouble = pista;

    bool orden = true;

    for (int i = 0; i < pistaOr; i++)
    {
        //cout << "Entrada #" << i << " al for." << endl;
        salidaPits[i] = 0;
    }

    //(int)vueltas;

    while (orden)
    {
        Randomizador(paradas, entradaPits, pistaOr);
        OrdenParadas(entradaPits, paradas);

        if (entradaPits[0] <= lluvia)
        {
            orden = false;
        }
    }

    std::cout << "Los datos insertados son los siguientes: \n"
         << "Tamaño de la pista: " << pistaDouble << " km.\n"
         << "Vueltas que debe dar: " << vueltas << "\n"
         << "El porcentaje de desgaste de las llantas es de: " << lluvia << "%.\n"
         << "Paradas por realizar: " << paradas << "\n"
         << endl;

    Pits(pista, lluvia, paradas, entradaPits);

    return 0;
};

int OptAsfalto(double pista, int asfalto, int paradas, double pistaOr, double vueltas, int *entradaPits, int *salidaPits){

    
    double pistaDouble = pista;

    bool orden = true;

    for (int i = 0; i < pistaOr; i++)
    {
        //cout << "Entrada #" << i << " al for." << endl;
        salidaPits[i] = 0;
    }

    //(int)vueltas;

    while (orden)
    {
        Randomizador(paradas, entradaPits, pistaOr);
        OrdenParadas(entradaPits, paradas);

        if (entradaPits[0] <= asfalto)
        {
            orden = false;
        }
    }

    std::cout << "Los datos insertados son los siguientes: \n"
         << "Tamaño de la pista: " << pistaDouble << " km.\n"
         << "Vueltas que debe dar: " << vueltas << "\n"
         << "El porcentaje de desgaste de las llantas es de: " << asfalto << "%.\n"
         << "Paradas por realizar: " << paradas << "\n"
         << endl;

    Pits(pista, asfalto, paradas, entradaPits);

    return 0;
};

int OptAgarre(double pista, int agarre, int paradas, double pistaOr, double vueltas, int *entradaPits, int *salidaPits){

    
    double pistaDouble = pista;

    bool orden = true;

    for (int i = 0; i < pistaOr; i++)
    {
        //cout << "Entrada #" << i << " al for." << endl;
        salidaPits[i] = 0;
    }

    //(int)vueltas;

    while (orden)
    {
        Randomizador(paradas, entradaPits, pistaOr);
        OrdenParadas(entradaPits, paradas);

        if (entradaPits[0] <= agarre)
        {
            orden = false;
        }
    }

    std::cout << "Los datos insertados son los siguientes: \n"
         << "Tamaño de la pista: " << pistaDouble << " km.\n"
         << "Vueltas que debe dar: " << vueltas << "\n"
         << "El porcentaje de desgaste de las llantas es de: " << agarre << "%.\n"
         << "Paradas por realizar: " << paradas << "\n"
         << endl;

    Pits(pista, agarre, paradas, entradaPits);

    return 0;
};

int main() {

    double pista;                       //distancia total de la pista
    int proxPits;                    
    int paradas;                        //cantidad de veces en las que deberá parar
    int pistaOr = 0;
    int i;
    double vueltas;

    int lluvia = 30;
    int asfalto = 45;
    int agarre = 65;

    cout << "Inserta la cantidad de vueltas que se realizarán" << endl;
    cin >> vueltas;
    cout << "\n";

    cout << "Inserta el tamaño de la pista." << '\n';
    cin >> pista;
    cout << '\n';

    double pistaDouble = pista;

    (double)pistaOr;

    pistaOr = pista;
    pista = pista * vueltas;

    (int)pistaOr; 
    pistaOr = (std::round(pistaOr));

    cout << "Recorrido de una vuelta " << pistaOr << endl;

    cout << "Recorrido total: " << pista << " km.\n" << endl;

    cout << "Cuántas veces debería de parar el coche en los pits?" << endl;
    cin >> paradas;
    cout << "\n";

    int entradaPits[paradas]; //distancia a recorrer para la siguiente vuelta una vez que se ingresa a los pits
    int salidaPits[paradas];  //distancia a recorrer una vez que se sale de los pits para la siguiente vuelta

    cout << "Que tipos de llantas tiene\n1)Para lluvia\n2)Para asfalto\n3)'Extra' agarre" << '\n';
    cin >> proxPits;
    cout << '\n';

    switch (proxPits)
    {
        case 1:            

            auto start = high_resolution_clock::now();

            OptLluvia(pista, lluvia, paradas, pistaOr, vueltas, entradaPits, salidaPits);

            auto stop = high_resolution_clock::now();

            auto durationSeg = duration_cast<seconds>(stop - start);
            auto durationMilli = duration_cast<milliseconds>(stop - start);
            auto durationMicro = duration_cast<microseconds>(stop - start);

            std::cout << "Le tomo " << durationSeg.count() << " segundos\n";
            std::cout << "Le tomo " << durationMilli.count() << " milisegundos\n";
            std::cout << "Le tomo " << durationMicro.count() << " microsegundos\n";

        break;

        case 2:
            auto start = high_resolution_clock::now();

            OptAsfalto(pista, asfalto, paradas, pistaOr, vueltas, entradaPits, salidaPits);

            auto stop = high_resolution_clock::now();

            auto durationSeg = duration_cast<seconds>(stop - start);
            auto durationMilli = duration_cast<milliseconds>(stop - start);
            auto durationMicro = duration_cast<microseconds>(stop - start);

            std::cout << "Le tomo " << durationSeg.count() << " segundos\n";
            std::cout << "Le tomo " << durationMilli.count() << " milisegundos\n";
            std::cout << "Le tomo " << durationMicro.count() << " microsegundos\n";
        break;

        case 3:
            auto start = high_resolution_clock::now();

            OptAsfalto(pista, agarre, paradas, pistaOr, vueltas, entradaPits, salidaPits);

            auto stop = high_resolution_clock::now();

            auto durationSeg = duration_cast<seconds>(stop - start);
            auto durationMilli = duration_cast<milliseconds>(stop - start);
            auto durationMicro = duration_cast<microseconds>(stop - start);

            std::cout << "Le tomo " << durationSeg.count() << " segundos\n";
            std::cout << "Le tomo " << durationMilli.count() << " milisegundos\n";
            std::cout << "Le tomo " << durationMicro.count() << " microsegundos\n";
        break;
        

        default:
            cout << "Inserte un valor correcto.\n" << endl;
            break;
        
    }

return 0;
}
