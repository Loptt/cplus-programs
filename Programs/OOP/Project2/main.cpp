#include <iostream>
#include <fstream>
#include <string>
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
    inputFile.open("Autores.txt");
    int cantidad = 0;

    bool validTema = false;
    bool validAutor = false;
    bool validInput;

    int idVideo, idTema, dd, mm, aa, autores, idAutor;
    string nombreVideo;
    Fecha fecha;

    while(inputFile >> idVideo >> nombreVideo >> idTema >> dd >> mm >> aa >> autores)
    {
        int arrPosAutores[autores];
        for (int counter = 0; counter < autores; ++counter)
        {
            inputFile >> idAutor;

            for (int counter2 = 0; counter2 < cantAutores; ++counter2)
            {
                if (arrAutores[counter2].getIdAutor() == idAutor)
                {
                    validAutor = true;
                }
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

            for (int counter = 0; counter < autores; ++counter)
            {
                if (!arrEjemploVideos[cantidad].agregarAutor(arrPosAutores[counter]))
                {
                    cout << "No se pudo agregar el siguiente id de Autor al video: " << arrPosAutores[counter];
                    cout << "ya sea que se repite el id, o la cantidad de autores maxima por video se ha alcanzado";
                    cout << endl;
                }
            }

            cantidad++;
        }
        else
        {
            cout << "El renglon numero " << cantidad+1 << " del archivo EjemploVideo contiene informacion erronea.";
            cout << " Por lo tanto no pudo ser agregada" << endl;
            cantidad++;
        }



    }
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



    return 0;
}