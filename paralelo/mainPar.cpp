#include <iostream>
#include <stdio.h>
#include <omp.h>
#include "pitsPar.hpp"

using namespace std;

int main() {

    double recorrido;    //distancia total de la pista
    double dist;        //distancia que puede recorrer entre paradas de pits
    int pits;           //cantidad de veces que puede parar en pits
    int i;
    double t_inicial = 0, t_final = 0;

    cout << "Inserta la distancia de la pista a recorrer." << '\n';
    cin >> recorrido;
    cout << '\n';

    recorrido = recorrido * 305.0;

    cout << "La distancia total a recorrer circuito es: " << recorrido << " km." << endl;

    cout << "Cuál es la distancia que puede recorrer el coche sin tener que cambiar llantas?" << '\n';
    cin >> dist;
    cout << '\n';

    cout << "Cuántas paradas se pueden hacer?" << '\n';
    cin >> pits;
    cout << '\n';

    int gas[pits];

    cout << "Inserta los km. donde se encuentran las gasolineras." << '\n';

    t_inicial = omp_get_wtime();
    #pragma omp parallel for private(i)
    for (i = 0; i < pits; i++) {

        cout << "Parada #" << i << '\n';
        cin >> pits;
        cout << '\n';

        gas[pits];
    }
    t_final = omp_get_wtime();

    cout << "Se tomó: " << t_final - t_inicial << " segundos." << endl;

    Pits(recorrido, dist, pits, gas);

    return 0;
}
