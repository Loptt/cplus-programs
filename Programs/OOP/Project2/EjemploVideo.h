//
// Created by Carlos Estrada on 2/27/18.
//

#ifndef PROJECT2_EJEMPLOVIDEO_H
#define PROJECT2_EJEMPLOVIDEO_H

#include <string>
#include "Fecha.h"

class EjemploVideo
{
public:
    EjemploVideo();

    void setIdVideo(int idVideo);
    void setNombre(std::string nombre);
    void setIdTema(int idTema);
    void setFechaElaboracion(Fecha fechaElaboracion);

    int getIdVideo() const {return idVideo;}
    std::string getNombre() const {return nombre;}
    int getIdTema() const {return idTema;}
    Fecha getFecha() const {return fechaElaboracion;}
    int getCantidadAutores() const {return cantidadAutores;}
    int getListaAutores(int index) const {return listaAutores[index];}

    bool agregarAutor(int idAutor);

private:

    int idVideo;
    std::string nombre;
    int idTema;
    Fecha fechaElaboracion;
    int cantidadAutores;
    int listaAutores[10];

};

EjemploVideo::EjemploVideo()
{
    idVideo = 0;
    nombre = "No asignado";
    idTema = 0;
    cantidadAutores = 0;
    fechaElaboracion.setFecha(0,0,2000);

    for (int iCounter = 0; iCounter < 10; ++iCounter)
    {
        listaAutores[iCounter] = 0;
    }
}

void EjemploVideo::setIdVideo(int idVideo)
{
    this->idVideo = idVideo;
}

void EjemploVideo::setNombre(std::string nombre)
{
    this->nombre = nombre;
}

void EjemploVideo::setIdTema(int idTema)
{
    this->idTema = idTema;
}

void EjemploVideo::setFechaElaboracion(Fecha fechaElaboracion)
{
    this->fechaElaboracion = fechaElaboracion;
}

bool EjemploVideo::agregarAutor(int idAutor)
{
    if (cantidadAutores < 10)
    {
        for (int iCounter = 0; iCounter < cantidadAutores; ++iCounter)
        {
            if (listaAutores[iCounter] == idAutor)
            {
                return false;
            }
        }

        listaAutores[cantidadAutores] = idAutor;
        cantidadAutores++;
        return true;
    }
    else
    {
        return false;
    }
}


#endif //PROJECT2_EJEMPLOVIDEO_H
