#include <iostream>
#include <fstream>
using namespace std;
#include "Fecha.h"
#include "Material.h"
#include "Reserva.h"
#include "Libro.h"
#include "Disco.h"
#include "Software.h"

int cargarMateriales(Material* arrMateriales[])
{
    ifstream inputFile;
    inputFile.open("Material.txt");

    int cantMaterial = 0;

    int idMaterial, duracion, numPags;
    string titulo, sistemaOper, autor;
    char tipo;

    while (inputFile >> idMaterial >> titulo >> tipo)
    {
        switch(tipo)
        {
            case 'L':
                inputFile >> numPags >> autor;
                arrMateriales[cantMaterial] = new Libro(idMaterial,titulo,numPags,autor);
                break;

            case 'D':
                inputFile >> duracion;
                arrMateriales[cantMaterial] = new Disco(idMaterial,titulo,duracion);
                break;

            case 'S':
                inputFile >> sistemaOper;
                arrMateriales[cantMaterial] = new Software(idMaterial, titulo, sistemaOper);
                break;

            default:
                cout << "ERROR" << endl;
        }

        cantMaterial++;
    }

    return cantMaterial;
}

int cargarReservas(Reserva arrReservas[])
{
    ifstream inputFile;
    inputFile.open("Reserva.txt");

    int cantReservas = 0;



}

int main()
{
    Material *arrMateriales[20];
    Reserva arrReservas[50];

    int cantMaterial = cargarMateriales(arrMateriales);
    int cantReservas = cargarReservas(arrReservas);

    return 0;
}
