#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

#include "Autor.h"
#include "Materia.h"
#include "Tema.h"
#include "EjemploVideo.h"

bool validarAutor(Autor arrAutores[], int cantAutores, int idAutor)
{
    for (int counter2 = 0; counter2 < cantAutores; ++counter2)
    {
        if (arrAutores[counter2].getIdAutor() == idAutor)
        {
            return true;
        }

        if (counter2 == cantAutores-1)
        {
            return false;
        }
    }
}

bool validarTema(Tema arrTemas[], int cantTemas, int idTema)
{
    for (int counter = 0; counter < cantTemas; ++counter)
    {
        if (arrTemas[counter].getIdTema() == idTema)
        {
            return true;
        }
    }

    return false;
}

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

        //Validar cada id de autor en la lista del texto
        for (int counter = 0; counter < cantLisAutores; ++counter)
        {
            inputFile >> idAutor;
            validAutor = validarAutor(arrAutores, cantAutores, idAutor);

            if(!validAutor)
            {
                break;
            }

            arrPosAutores[counter] = idAutor;
        }

        validTema = validarTema(arrTemas, cantTema, idTema);

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

    return cantidad;
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
        cout << "     " << arrMaterias[iCounter].getNombre();
        cout << endl;
    }

    cout << endl;
}

void muestraTemas(Tema arrTemas[], int cantTemas)
{
    cout << "ID de Tema   "  << "ID de Materia   "<< "Nombre de Tema" << endl;

    for (int iCounter = 0; iCounter < cantTemas; ++iCounter)
    {
        cout << setw(7) << arrTemas[iCounter].getIdTema();
        cout << setw(13) << arrTemas[iCounter].getIdMateria();
        cout << "        " << arrTemas[iCounter].getNombre();
        cout << endl;
    }

    cout << endl;
}

void muestraAutores(Autor arrAutores[], int cantAutores)
{
    cout << "ID de Autor   " << "Nombre de Autor" << endl;

    for (int iCounter = 0; iCounter < cantAutores; ++iCounter)
    {
        cout << setw(6) << arrAutores[iCounter].getIdAutor();
        cout << "       " << arrAutores[iCounter].getNombre();
        cout << endl;
    }

    cout << endl;
}

int agregaNuevoVideo(EjemploVideo arrEjemploVideos[], Tema arrTemas[], Autor arrAutores[],
                     int cantVideos, int cantTemas, int cantAutores)
{
    int idVideo, idTema, idAutor, cantidadUsuarioAutores, dd, mm, aa;
    string nombreVideo;
    Fecha fecha;

    bool validData = true;

    cout << "Introduce el id del Video" << endl << "-->";

    do
    {
        cin >> idVideo;

        for (int iCounter = 0; iCounter < cantVideos; ++iCounter)
        {
            if (arrEjemploVideos[iCounter].getIdVideo() == idVideo)
            {
                validData = false;
                cout << "ID de video ya existe. Por favor introduce uno valido" << endl;
                break;
            }
            else
            {
                validData = true;
            }
        }

    }
    while(!validData);

    cout << endl;
    cin.ignore();

    arrEjemploVideos[cantVideos++].setIdVideo(idVideo);

    cout << "Introduce el nombre del video" << endl << "-->";
    getline(cin, nombreVideo);

    arrEjemploVideos[cantVideos].setNombre(nombreVideo);

    cout << "Introduce el ID del tema" << endl << "-->";

    do
    {
        cin >> idTema;
        validData = validarTema(arrTemas, cantTemas, idTema);

        if (!validData)
        {
            cout << "El ID de tema no es valido. Por favor introduce uno nuevamente" << endl;
        }

    }
    while (!validData);

    cout << "Introduce el dia de elaboracion -->";
    cin >> dd;
    cout << endl;

    cout << "Introduce el mes de elaboracion en numero -->";
    cin >> mm;
    cout << endl;

    cout << "Introduce el año de elaboracion  -->";
    cin >> aa;
    cout << endl;

    fecha.setFecha(dd, mm, aa);
    arrEjemploVideos[cantVideos].setFechaElaboracion(fecha);

    cout << "Introduce la cantidad de autores que tiene el video -->";

    do
    {
        cin >> cantidadUsuarioAutores;

        if (cantidadUsuarioAutores > 10 || cantidadUsuarioAutores < 1)
        {
            validData = false;
            cout << "La cantidad debe ser un numero entre 1 y 10" << endl;
        }
        else
        {
            validData = true;
        }
    }
    while(!validData);

    for (int iCounter = 0; iCounter < cantidadUsuarioAutores; ++iCounter)
    {
        cout << "Introduce el ID del autor " << iCounter+1 << " -->";

        do
        {
            cin >> idAutor;
            cout << endl;
            validData = validarAutor(arrAutores, cantAutores, idAutor);

            if (!validData)
            {
                cout << "El ID ingresado no corresponde a ningun autor. Vuelve a introducirlo." << endl;
            }
        }
        while(!validData);

        validData = true;

        do
        {
            validData = arrEjemploVideos[cantVideos].agregarAutor(idAutor);

            if (!validData)
            {
                cout << "El ID de autor ya ha sido agregaado. Por favor introduce otro" << endl;
                cin >> idAutor;
            }
        }
        while(!validData);
    }

    return cantVideos;

}

int main()
{
    Materia arrMaterias[5];
    Tema arrTemas[10];
    Autor arrAutores[10];
    EjemploVideo arrEjemploVideos[20];

    int cantidadMaterias, cantidadTemas, cantidadAutores, cantidadVideos;

    char respuesta;

    cantidadMaterias = cargarMaterias(arrMaterias);
    cantidadTemas = cargarTemas(arrTemas);
    cantidadAutores = cargarAutores(arrAutores);
    cantidadVideos = cargarEjemploVideos(arrEjemploVideos, arrTemas, arrAutores, cantidadTemas, cantidadAutores);

    do
    {
        respuesta = muestraMenu();

        switch (respuesta)
        {
            case 'a':
                muestraMaterias(arrMaterias, cantidadMaterias);
                muestraTemas(arrTemas, cantidadTemas);
                muestraAutores(arrAutores, cantidadAutores);

                break;
            case 'b':
                cantidadVideos = agregaNuevoVideo(arrEjemploVideos, arrTemas, arrAutores, cantidadTemas,
                                 cantidadAutores, cantidadVideos);

                break;
            case 'c':
                break;
            case 'd':
                break;
            case 'e':
                break;
            case 'f':
                break;
            case 'g':
                break;
            default:
                cout << "Opcion invalida, vuelve a intentar" << endl << endl;
                break;
        }
    }
    while(respuesta != 'g');

    return 0;
}