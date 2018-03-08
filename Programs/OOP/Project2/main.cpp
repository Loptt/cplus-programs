#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

#include "Autor.h"
#include "Materia.h"
#include "Tema.h"
#include "EjemploVideo.h"

int cargarMaterias(Materia arrMaterias[])
{
    ifstream inputFile;
    inputFile.open("Materias.txt");
    int cantidad = 0;

    int idMateria;
    string nombreMateria;

    while (inputFile >> idMateria && getline(inputFile, nombreMateria))
    {
        arrMaterias[cantidad].setIdMateria(idMateria);
        arrMaterias[cantidad].setNombre(nombreMateria);
        cantidad++;
    }

    inputFile.close();

    return cantidad;
}

int cargarTemas(Tema arrTemas[])
{
    ifstream inputFile;
    inputFile.open("Temas.txt");
    int cantidad = 0;

    int idMateria, idTema;
    string nombreTema;

    while (inputFile >> idTema >> idMateria && getline(inputFile, nombreTema))
    {
        arrTemas[cantidad].setIdTema(idTema);
        arrTemas[cantidad].setIdMateria(idMateria);
        arrTemas[cantidad].setNombre(nombreTema);
        cantidad++;
    }

    inputFile.close();

    return cantidad;
}

int cargarAutores(Autor arrAutores[])
{
    ifstream inputFile;
    inputFile.open("Autores.txt");
    int cantidad = 0;

    int idAutor;
    string nombreAutor;

    while (inputFile >> idAutor && getline(inputFile, nombreAutor))
    {
        arrAutores[cantidad].setIdAutor(idAutor);
        arrAutores[cantidad].setNombre(nombreAutor);
        cantidad++;
    }

    inputFile.close();

    return cantidad;
}

int cargarEjemploVideos(EjemploVideo arrEjemploVideos[], Tema arrTemas[], Autor arrAutores[], int cantTema,
                        int cantAutores)
{
    ifstream inputFile;
    inputFile.open("EjemploVideo.txt");
    int cantidad = 0;

    bool validTema = false;
    bool validAutor = true;

    int idVideo, idTema, dd, mm, aa, cantLisAutores, idAutor;
    string nombreVideo;
    Fecha fecha;

    while(inputFile >> idVideo >> nombreVideo >> idTema >> dd >> mm >> aa >> cantLisAutores)
    {
        int arrPosAutores[cantLisAutores];
        for (int counter = 0; counter < cantLisAutores; ++counter)
        {
            inputFile >> idAutor;

            for (int counter2 = 0; counter2 < cantAutores; ++counter2)
            {
                if (arrAutores[counter2].getIdAutor() == idAutor)
                {
                    break;
                }

                if (counter2 == cantAutores-1)
                {
                    cout << idAutor << endl;
                    validAutor = false;
                }
            }

            if(!validAutor)
            {
                break;
            }

            arrPosAutores[counter] = idAutor;
        }

        for (int counter = 0; counter < cantTema; ++counter)
        {
            if (arrTemas[counter].getIdTema() == idTema)
            {
                validTema = true;
            }
        }

        if (validAutor && validTema)
        {
            fecha.setFecha(dd,mm,aa);

            arrEjemploVideos[cantidad].setIdVideo(idVideo);
            arrEjemploVideos[cantidad].setNombre(nombreVideo);
            arrEjemploVideos[cantidad].setIdTema(idTema);
            arrEjemploVideos[cantidad].setFechaElaboracion(fecha);

            for (int counter = 0; counter < cantLisAutores; ++counter)
            {
                if (!arrEjemploVideos[cantidad].agregarAutor(arrPosAutores[counter]))
                {
                    cout << "No se pudo agregar el siguiente id de Autor al video: " << arrPosAutores[counter];
                    cout << " ya sea que se repite el id, o la cantidad de autores maxima por video se ha alcanzado";
                    cout << endl;
                }
            }

            cantidad++;
        }
        else
        {
            cout << "El renglon numero " << cantidad+1 << " del archivo EjemploVideo contiene informacion erronea.";
            cout << " Por lo tanto no pudo ser agregada" << endl;
        }

        validTema = false;
        validAutor = true;

    }
}

char muestraMenu()
{
    cout << "MENU:" << endl;
    cout << "a) Consultar información de Materias, Temas y Autores." << endl;
    cout << "b) Dar de alta Videos de Ejemplo." << endl;
    cout << "c) Consultar la lista de Videos por tema." << endl;
    cout << "d) Consultar la lista de Videos por materia" << endl;
    cout << "e) Consultar lista de Videos." << endl;
    cout << "f) Consultar videos por autor." << endl;
    cout << "g) Terminar." << endl << endl;

    char respuesta;
    cin >> respuesta;

    return respuesta;
}

void muestraMaterias(Materia arrMaterias[], int cantMaterias)
{
    cout << "ID de Materia   " << "Nombre de Materia" << endl;

    for (int iCounter = 0; iCounter < cantMaterias; ++iCounter)
    {
        cout << setw(10) << arrMaterias[iCounter].getIdMateria();
        cout << "    " << arrMaterias[iCounter].getNombre();
        cout << endl;
    }

    cout << endl;
}

void muestraTemas(Tema arrTemas[], int cantTemas)
{
    cout << "ID de Tema   "  << "ID de Materia   "<< "Nombre de Materia" << endl;

    for (int iCounter = 0; iCounter < cantTemas; ++iCounter)
    {
        cout << setw(10) << arrTemas[iCounter].getIdTema();
        cout << setw(10) << arrTemas[iCounter].getIdMateria();
        cout << "    " << arrTemas[iCounter].getNombre();
        cout << endl;
    }

    cout << endl;
}

void muestraAutores(Autor arrAutores[], int cantAutores)
{
    cout << "ID de Materia   " << "Nombre de Materia" << endl;

    for (int iCounter = 0; iCounter < cantAutores; ++iCounter)
    {
        cout << setw(10) << arrAutores[iCounter].getIdAutor();
        cout << "    " << arrAutores[iCounter].getNombre();
        cout << endl;
    }

    cout << endl;
}

int main()
{
    Materia arrMaterias[5];
    Tema arrTemas[10];
    Autor arrAutores[10];
    EjemploVideo arrEjemploVideos[20];

    int cantidadMaterias, cantidadTemas, cantidadAutores, cantidadVideos;

    cantidadMaterias = cargarMaterias(arrMaterias);
    cantidadTemas = cargarTemas(arrTemas);
    cantidadAutores = cargarAutores(arrAutores);
    cantidadVideos = cargarEjemploVideos(arrEjemploVideos, arrTemas, arrAutores, cantidadTemas, cantidadAutores);

    char respuesta = muestraMenu();

    while (respuesta != 'g')
    {
        switch (respuesta)
        {
            case 'a':
                muestraMaterias(arrMaterias, cantidadMaterias);
                muestraTemas(arrTemas, cantidadTemas);
                muestraAutores(arrAutores, cantidadAutores);
                
                break;
            case 'b':
                break;
            case 'c':
                break;
            case 'd':
                break;
            case 'e':
                break;
            case 'f':
                break;
            default:
                cout << "Opcion invalida, vuelve a intentar" << endl << endl;
        }
        respuesta = muestraMenu();
    }



    return 0;
}