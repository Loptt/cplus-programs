//
// Created by Carlos Estrada on 2/27/18.
//

#ifndef PROJECT2_MATERIA_H
#define PROJECT2_MATERIA_H

#include <string>

class Materia
{
public:
    Materia();
    Materia(int, std::string);

    int getIdMateria() const {return idMateria;}
    std::string getNombre() const {return nombre;}

    void setIdMateria(int idMateria);
    void setNombre(std::string nombre);

private:
    int idMateria;
    std::string nombre;
};

Materia::Materia()
{
    idMateria = 0;
    nombre = "No asignado";
}

Materia::Materia(int idMateria, std::string nombre)
{
    this->idMateria = idMateria;
    this->nombre = nombre;
}

void Materia::setIdMateria(int idMateria)
{
    this->idMateria = idMateria;
}

void Materia::setNombre(std::string nombre)
{
    this->nombre = nombre;
}


#endif //PROJECT2_MATERIA_H
