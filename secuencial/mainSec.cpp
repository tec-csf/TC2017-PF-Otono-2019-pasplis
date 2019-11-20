#include <iostream>
#include <stdio.h>
#include <chrono>
#include <ctime>
#include "pitsSec.hpp"

using namespace std::chrono;
using namespace std;

int main() {

    double pista;       //distancia total de la pista
    double proxPits;    //distancia que puede recorrer entre paradas
    double vueltas;
    int paradas;        //cantidad de veces en las que deberá parar
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

    cout << "Cuántas paradas permitidas le quedan?" << '\n';
    cin >> paradas;
    cout << '\n';

    int gas[paradas];

    cout << "Inserta los km. donde se encuentran las gasolineras." << '\n';

    for (i = 0; i < paradas; i++) {

        cout << "Parada #" << i << '\n';
        cin >> paradas;
        cout << '\n';

        gas[paradas];
    }

    auto start = high_resolution_clock::now();

    cout << "Puede llegar a hacer " <<Pits(pista, proxPits, paradas, gas) << " paradas en los pits.\n" << endl;

    auto stop = high_resolution_clock::now();

    auto durationSeg = duration_cast<seconds>(stop - start);
    auto durationMilli = duration_cast<milliseconds>(stop - start);
    auto durationMicro = duration_cast<microseconds>(stop - start);

    cout << "Le tomo " << durationSeg.count() << " segundos\n";
    cout << "Le tomo " << durationMilli.count() << " milisegundos\n";
    cout << "Le tomo " << durationMicro.count() << " microsegundos\n";

return 0;
}
