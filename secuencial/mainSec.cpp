#include <iostream>
#include <stdio.h>
#include <chrono>
#include "pitsSec.hpp"

using namespace std::chrono;
using namespace std;

int main() {

    double pista;                       //distancia total de la pista
    double vueltas;                     //cantidad de vueltas que se realizarán
    double proxPits;                    //distancia que puede recorrer entre paradas
    int paradas = 5;                    //cantidad de veces en las que deberá parar
    int entradaPits[] = {3,6,9,12,15};  //distancia en la que se encuentran las próximas paradas
    int i;

    cout << "Inserta la cantidad de vueltas que se realizarán" << endl;
    cin >> vueltas;
    cout << "\n";

    cout << "Inserta el tamaño de la pista." << '\n';
    cin >> pista;
    cout << '\n';

    pista = pista * vueltas;

    cout << "Recorrido total: " << pista << " km.\n" << endl;

    cout << "Cuál es la distancia que puede recorrer el coche sin cambiar de llantas?" << '\n';
    cin >> proxPits;
    cout << '\n';

    cout <<"Le quedan "<< paradas << " paradas permitidas.\n" << endl;

    cout << "Los datos insertados son los siguientes: \n" << "Tamaño de la pista: " << pista << " km.\n" << "Vueltas que debe dar: " << vueltas << "\n" << "Distancia que le queda por llegar a los pits: "<< proxPits << " km.\n" << "Paradas por realizar: " << paradas << "\n" << endl;

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
