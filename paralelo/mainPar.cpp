#include <iostream>
#include <stdio.h>
#include <omp.h>
#include "pits.hpp"

using namespace std;

int main() {

    double recorrido;    //distancia total de la pista
    double dist;        //distancia que puede recorrer entre paradas de pits
    int paradas;        //cantidad de veces que puede parar en pits
    int i;
    double t_inicial = 0, t_final = 0;

    cout << "Inserta la distancia de la pista a recorrer." << '\n';
    cin >> recorrido;
    cout << '\n';

    recorrido = recorrido * 305.0;

    cout << "Cuál es la distancia que puede recorrer el coche sin cambiar llantas?" << '\n';
    cin >> dist;
    cout << '\n';

    cout << "Cuántas gasolineras hay?" << '\n';
    cin >> paradas;
    cout << '\n';

    int gas[paradas];

    cout << "Inserta los km. donde se encuentran las gasolineras." << '\n';

    t_inicial = omp_get_wtime();
    #pragma omp parallel for private(i)
    for (i = 0; i < paradas; i++) {

        cout << "Parada #" << i << '\n';
        cin >> paradas;
        cout << '\n';

        gas[paradas];
    }
    t_final = omp_get_wtime();

    cout << "Se tomó: " << t_final - t_inicial << " segundos." << endl;

    Pits(recorrido, dist, paradas, gas);

    return 0;
}
