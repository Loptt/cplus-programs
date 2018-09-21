/*
Creado por:
Carlos Estrada A01039919
José Guillermo Saldaña A01039888
*/


#include <iostream>
#include "Patio.h"
#include "Bomba.h"
using namespace std;

int main()
{
    int largo, ancho, temp;
    cout << "Por favor ingrese el largo de su patio: ";
    cin >> largo;

    cout << "Por favor ingrese el ancho de su patio: ";
    cin >> ancho;

    cout << "Por favor ingrese la temperatura actual: ";
    cin >> temp;

    Patio miPatio(largo, ancho);

    int area = miPatio.caluclarArea();

    Bomba miBomba("LaMejorMarca", 3000);

    miBomba.calcularRiego(temp, area);

    return 0;
}
