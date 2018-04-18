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

    inputFile.close();

    return cantMaterial;
}

int cargarReservas(Reserva arrReservas[])
{
    ifstream inputFile;
    inputFile.open("Reserva.txt");

    int cantReservas = 0;

    int idCliente, idMaterial;
    Fecha fechaReservacion;

    while(inputFile >> fechaReservacion >> idMaterial >> idCliente)
    {
        arrReservas[cantReservas].setIdMaterial(idMaterial);
        arrReservas[cantReservas].setIdCliente(idCliente);
        arrReservas[cantReservas].setFechaReservacion(fechaReservacion);

        cantReservas++;
    }

    inputFile.close();

    return cantReservas;

}

char mostrarMenu()
{
    char respuesta;

    cout << "------------------MENU----------------------" << endl << endl;
    cout << "a) Consultar la lista de materiales" << endl;
    cout << "b) Consultar la lista de reservaciones" << endl;
    cout << "c) Consultar las reservaciones de un material" << endl;
    cout << "d) Consultar las reservaciones de una fecha" << endl;
    cout << "e) Hacer una reservacion" << endl;
    cout << "f) Terminar" << endl;

    cin >> respuesta;

    return respuesta;
}

void mostrarListaMateriales(Material *arrMateriales[], int cant)
{
    cout << "Material Disponible: " << endl << endl;

    for (int iCounter = 0; iCounter < cant; ++iCounter)
    {
        arrMateriales[iCounter]->muestra();
        cout << endl;
    }
}

void mostrarListaReservas(Reserva arrReservas[], int cant)
{
    for (int iCounter = 0; iCounter < cant; ++iCounter)
    {
        cout << "Reserva No: " << iCounter+1 << endl;
        cout << "ID del Material: " << arrReservas[iCounter].getIdMaterial() << endl;
        cout << "ID del Cliente: " << arrReservas[iCounter].getIdCliente() << endl;
        cout << "Fecha de reservación: " << arrReservas[iCounter].getFechaReservacion() << endl;
        cout << endl;

    }

    cout << endl;
}


void mostrarReservacionesMaterial(Material *arrMateriales[], Reserva arrReservas[], int cantM, int cantR)
{
    string nombre;
    int idMaterial = 0;
    int cantidadDias = 0;
    bool bEncontrado =  false;

    cout << "Introduzca el nombre del material: " << endl;

    do
    {
        cin >> nombre;
        for (int iCounter = 0; iCounter < cantM; ++iCounter)
        {
            if (arrMateriales[iCounter]->getTitulo() == nombre)
            {
                idMaterial = arrMateriales[iCounter]->getIdMaterial();
                cantidadDias = arrMateriales[iCounter]->cantidadDiasPrestamo();
                bEncontrado = true;
            }

        }

        if (!bEncontrado)
        {
            cout << "El titulo del material no existe, intenta con otro..." << endl;
        }
    }
    while(!bEncontrado);

    for (int iCounter = 0; iCounter < cantR; ++iCounter)
    {
        if (idMaterial == arrReservas->getIdMaterial())
        {
            cout << "Nombre: " << nombre << endl;
            cout << "Fecha de inicio de reservacion: " << arrReservas[iCounter].getFechaReservacion() << endl;
            cout << "Fecha de fin de reservacion: " << arrReservas[iCounter].getFechaReservacion() +
                    cantidadDias << endl;
        }
    }

}

void mostrarReservacionesFecha(Material *arrMateriales[], Reserva arrReservas[], int cantM, int cantR)
{
    Fecha fecha;
    Fecha fechaReservacion;
    int diasPrestamo = 0;
    int posicionMaterial = 0;
    bool encontrado = false;

    cout << "Introduce una fecha: " << endl;
    cin >> fecha;

    cout << "Reservaciones para " << fecha << endl << endl;

    for (int iCounter = 0; iCounter < cantR; ++iCounter)
    {
        //Si la fecha dada es mayor que la fecha de reserva, esta puede estar en el rango de prestamo
        if (arrReservas[iCounter].getFechaReservacion() <= fecha)
        {
            fechaReservacion = arrReservas[iCounter].getFechaReservacion();

            //Conseguir la cantidad de dias de prestamo para el material de esa reservacion
            for (int iCounter2 = 0; iCounter2 < cantM; ++iCounter2)
            {
                if (arrReservas[iCounter].getIdMaterial() == arrMateriales[iCounter2]->getIdMaterial())
                {
                    diasPrestamo = arrMateriales[iCounter2]->cantidadDiasPrestamo();
                    posicionMaterial = iCounter2;
                }
            }

            //Checar si la fecha mas la cantidad de dias de prestamo es mayor que la fecha para
            //asegurar que se encuentre en el rango
            if (fechaReservacion + diasPrestamo >= fecha)
            {
                encontrado = true;
                arrMateriales[posicionMaterial]->muestra();
                cout << "Fecha de prestamo " << fechaReservacion << endl;
                cout << endl;
            }
        }
    }

    if (!encontrado)
    {
        cout << "No se encontraron reservaciones en esa fecha" << endl;
    }
}

void hacerReservacion(Material *arrMateriales[], Reserva arrReservas[], int cantM, int cantR)
{
    cout << "Introduce la canti";
}

int main()
{
    Material *arrMateriales[20];
    Reserva arrReservas[50];

    int cantMaterial = cargarMateriales(arrMateriales);
    int cantReservas = cargarReservas(arrReservas);

    char respuesta;

    do
    {
        respuesta = mostrarMenu();

        switch (respuesta)
        {
            case 'a':
                mostrarListaMateriales(arrMateriales, cantMaterial);
                break;

            case 'b':
                mostrarListaReservas(arrReservas, cantReservas);
                break;

            case 'c':
                mostrarReservacionesMaterial(arrMateriales, arrReservas, cantMaterial, cantReservas);
                break;

            case 'd':
                mostrarReservacionesFecha(arrMateriales, arrReservas, cantMaterial, cantReservas);
                break;

            case 'e':
                hacerReservacion(arrMateriales, arrReservas, cantMaterial, cantReservas);
                break;

            default:
                break;
        }
    }
    while (respuesta != 'f');

    return 0;
}
