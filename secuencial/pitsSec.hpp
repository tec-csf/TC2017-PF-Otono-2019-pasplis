#include <iostream>
#include <stdio.h>

using namespace std;

int Pits(double proxPits, double distancia, int paradas, int entradaPits[]){

    double contDistancia = 0.0;   
    double alfa = 0.0; 
    int beta = 0; 

    while (contDistancia < proxPits) {

        if (alfa < paradas && entradaPits[beta] <= (contDistancia + distancia)) {
        contDistancia = entradaPits[beta];
        beta++;
        } //fin loop if en la que se suma la distancia recorrida
        else{
        contDistancia += distancia;
        }

        if (contDistancia < proxPits) {
        alfa++;
        }

    }

    cout << "Puede llegar a hacer " << alfa << " paradas.\n" << endl;

    if (alfa < 10)
    {
        cout << "Puede pasar a los pits sin problema alguno.\n" << endl;
    }else if (alfa > 11)
    {
       cout << "Le recomendamos sacar su vehiculo de la competencia\n" << endl;
    }


    return alfa;
};