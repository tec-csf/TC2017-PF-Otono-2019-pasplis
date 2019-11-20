#include <iostream>
#include <stdio.h>

using namespace std;

int Pits(double proxPits, double distancia, int paradas, int gas[]){

    double contDistancia = 0;   
    double alfa = 0; 
    int beta = 0; 

    while (contDistancia < proxPits) {

        if (alfa < paradas && gas[beta] <= (contDistancia + distancia)) {
        contDistancia = gas[beta];
        beta++;
        } //fin loop if en la que se suma la distancia recorrida
        else{
        contDistancia += distancia;
        }

        if (contDistancia < proxPits) {
        alfa++;
        }

    }

    return alfa;
};