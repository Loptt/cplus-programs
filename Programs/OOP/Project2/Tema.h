//
// Created by Carlos Estrada on 2/27/18.
//

#ifndef PROJECT2_TEMA_H
#define PROJECT2_TEMA_H

#include <string>

class Tema
{
public:
    Tema();
    Tema(int, std::string, int);

    void setIdTema(int idTema);
    void setNombre(std::string nombre);
    void setIdMateria(int idMateria);

    int getIdTema() const {return idTema;}
    std::string getNombre() const {return nombre;}
    int getIdMateria() const {return idMateria;}

private:
    int idTema;
    std::string nombre;
    int idMateria;
};

Tema::Tema()
{
    idTema = 0;
    nombre = "No asignado";
    idMateria = 0;
}

Tema::Tema(int idTema, std::string nombre, int idMateria)
{
    this->idTema = idTema;
    this->nombre = nombre;
    this->idMateria = idMateria;
}

void Tema::setIdTema(int idTema)
{
    this->idTema = idTema;
}

void Tema::setNombre(std::string nombre)
{
    this->nombre = nombre;
}

void Tema::setIdMateria(int idMateria)
{
    this->idMateria = idMateria;
}


#endif //PROJECT2_TEMA_H
