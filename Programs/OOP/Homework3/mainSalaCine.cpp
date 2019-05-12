/*
Code created by Carlos Estrada
All rights reserved
29/01/2017
Programacion Orientada a Objetos
*/

#include <iostream>
#include "SalaCine.h"

using namespace std;

int main()
{
    SalaCine sala1;
    int lugares;
    string pelicula;

    cout << "Cuantos lugares tiene la sala? " << endl;
    cin >> lugares;
    sala1.setLugares(lugares);

    cout << "Cual es el nombre de la pelicula " << endl;
    cin.ignore();
    getline(cin, pelicula);
    sala1.setPelicula(pelicula);

    char respuesta;
    int cantidadBoletos = 0;

    do
    {
        cout << "Desea comprar boletos para la funcion " << sala1.getPelicula() << "?" << endl;
        cout << "s/n  >>  ";
        cin >> respuesta;

        if (respuesta == 's')
        {
            cout << "Cuantos boletos desea comprar?" << endl;
            cin >> cantidadBoletos;

            if (cantidadBoletos > sala1.getLugares())
            {
                cout << "Lo sentimos, ya no hay suficientes lugares." << endl << endl;
            }
            else
            {
                sala1.compraBoleto(cantidadBoletos);
                cout << cantidadBoletos << " boletos comprados exitosamente." << endl << endl;
            }

            cout << "Quedan " << sala1.getLugares() << " boletos para la pelicula " << sala1.getPelicula() << endl;
        }
    }
    while (respuesta == 's');

    return 0;
}