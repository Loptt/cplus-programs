/*
Code created by Carlos Estrada
All rights reserved
29/01/2017
Programacion Orientada a Objetos
*/

#include <iostream>
using namespace std;

#include "Esfera.h"


int main()
{
    Esfera esfera1;
    float radio = 0.0;

    cout << "Radio: " << esfera1.getRadio() << endl;
    cout << "Area: " << esfera1.calcArea() << endl;
    cout << "Volumen: " << esfera1.calcVolum() << endl;

    cout << "Introduce un valor para el radio >> ";
    cin >> radio;
    cout << endl;

    esfera1.setRadio(radio);

    cout << "Radio: " << esfera1.getRadio() << endl;
    cout << "Area: " << esfera1.calcArea() << endl;
    cout << "Volumen: " << esfera1.calcVolum() << endl;

    return 0;
}