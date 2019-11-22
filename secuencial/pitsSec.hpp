#include <iostream>
#include <stdio.h>

using namespace std;

int PosiblesAccidentes(int paradas, int entradaPits[], int pistaOr){
    srand(time(NULL));
    for (int i = 0; i < paradas; i++)
    {
        entradaPits[i] = rand()%pistaOr;
    }
    
};

void AcomodaValores(int *var1, int *var2){
    int temporal = *var1;
    *var1 = *var2;
    *var2 = temporal;
};

void PosiblesParadas(int entradaPits[], int paradas){
    
    int initium, finis;

    for (initium = 0; initium < paradas; initium++)
   
    for (finis = 0; finis < (paradas-1-initium); finis++)
        if (entradaPits[finis] > entradaPits[finis-1])
        {
            AcomodaValores(&entradaPits[finis], &entradaPits[finis+1]);    
        }
        
};

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

    if (alfa < 10)
    {
        cout << "Puede pasar a los pits sin problema alguno.\n"
             << endl;
    }
    else if (alfa > 11)
    {
        cout << "Le recomendamos sacar su vehiculo de la competencia\n"
             << endl;
    }

    return alfa;
};