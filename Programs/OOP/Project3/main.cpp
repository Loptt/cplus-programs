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

    cout << "A cargar reservas " << endl;

    while(inputFile >> fechaReservacion >> idMaterial >> idCliente)
    {
        arrReservas[cantReservas].setIdMaterial(idMaterial);
        arrReservas[cantReservas].setIdCliente(idCliente);
        arrReservas[cantReservas].setFechaReservacion(fechaReservacion);

        cantReservas++;
        cout << "Cargando reserva no " << cantReservas-1 << endl;
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

bool validarRangoFechas(Fecha fechaInicial, Fecha fechaFinal, Fecha fechaMeta)
{
    return !(fechaInicial <= fechaMeta && fechaFinal >= fechaMeta);
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
    int idMaterial = 0;
    int cantidadDias = 0;
    bool bEncontrado =  false;
    string nombre;

    cout << "Introduzca el ID del material: " << endl;

    do
    {
        cin >> idMaterial;
        for (int iCounter = 0; iCounter < cantM; ++iCounter)
        {
            if (arrMateriales[iCounter]->getIdMaterial() == idMaterial)
            {
                nombre = arrMateriales[iCounter]->getTitulo();
                cantidadDias = arrMateriales[iCounter]->cantidadDiasPrestamo();
                bEncontrado = true;
            }

        }

        if (!bEncontrado)
        {
            cout << "El ID del material no existe, intenta con otro..." << endl;
        }
    }
    while(!bEncontrado);

    bEncontrado = false;

    for (int iCounter = 0; iCounter < cantR; ++iCounter)
    {
        if (idMaterial == arrReservas[iCounter].getIdMaterial())
        {
        	bEncontrado = true;
            cout << "Nombre: " << nombre << endl;
            cout << "Fecha de inicio de reservacion: " << arrReservas[iCounter].getFechaReservacion() << endl;
            cout << "Fecha de fin de reservacion: " << arrReservas[iCounter].getFechaReservacion() +
                    cantidadDias << endl << endl;
        }
    }


    if (!bEncontrado)
    {
    	cout << "No se encontraron reservaciones para ese material." << endl;
    }

}

void mostrarReservacionesFecha(Material *arrMateriales[], Reserva arrReservas[], int cantM, int cantR)
{
    Fecha fecha;
    Fecha fechaReservacion;
    int diasPrestamo = 0;
    int posicionMaterial = 0;
    bool encontrado = false;

    cout << "Introduzca una fecha: " << endl;
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
        cout << "No se encontraron reservaciones en esa fecha" << endl << endl;
    }
}

int hacerReservacion(Material *arrMateriales[], Reserva arrReservas[], int cantM, int cantR)
{
    int idCliente;
    int idMaterial;
    int cantidadDias = 0;

    Fecha fecha;

    bool validMaterial = false;
    bool validFecha1 = true;
    bool validFecha2 = true;

    cout << "Introduzca su ID de cliente:" << endl;
    cin >> idCliente;

    cout << "Introduzca el ID del material:" << endl;

    do
    {
        cin >> idMaterial;

        for (int iCounter = 0; iCounter < cantM; ++iCounter)
        {
            if (arrMateriales[iCounter]->getIdMaterial() == idMaterial)
            {
                validMaterial = true;
                cantidadDias = arrMateriales[iCounter]->cantidadDiasPrestamo();
            }
        }

        if (!validMaterial)
        {
            cout << "Ese ID no existe, por favor intenta con otro:" << endl;
        }

    }
    while (!validMaterial);

    cout << "Introduzca la fecha de reservacion:" << endl;
    cin >> fecha;

    Fecha fechaReserva;

    for (int iCounter = 0; iCounter < cantR; ++iCounter)
    {
        if (arrReservas[iCounter].getIdMaterial() == idMaterial)
        {
            fechaReserva = arrReservas[iCounter].getFechaReservacion();
            validFecha1 = validarRangoFechas(fechaReserva, fechaReserva + cantidadDias, fecha);
            validFecha2 = validarRangoFechas(fecha, fecha + cantidadDias, fechaReserva);
        }
    }

    if (validFecha1 && validFecha2)
    {
        arrReservas[cantR].setIdCliente(idCliente);
        arrReservas[cantR].setIdMaterial(idMaterial);
        arrReservas[cantR].setFechaReservacion(fecha);
        cantR++;

        cout << "Reserva realizada exitosamente." << endl << endl;
    }
    else
    {
        cout << "No se pudo realizar la reservacion debido a que el material esta en uso durante esa fecha." << endl;
    }

    return cantR;
}

void guardarReservaciones(Reserva arrReservas[], int cantR)
{
    ofstream outputFile;
    outputFile.open("Reserva.txt");

    for (int iCounter = 0; iCounter < cantR; ++iCounter)
    {
        outputFile << arrReservas[iCounter].getFechaReservacion().getDia() << " ";
        outputFile << arrReservas[iCounter].getFechaReservacion().getMes() << " ";
        outputFile << arrReservas[iCounter].getFechaReservacion().getAnio() << " ";
        outputFile << arrReservas[iCounter].getIdMaterial() << " ";
        outputFile << arrReservas[iCounter].getIdCliente() << endl;
    }

    outputFile.close();
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
                cantReservas = hacerReservacion(arrMateriales, arrReservas, cantMaterial, cantReservas);
                break;

            default:
                break;
        }
    }
    while (respuesta != 'f');

    guardarReservaciones(arrReservas, cantReservas);

    return 0;
}
