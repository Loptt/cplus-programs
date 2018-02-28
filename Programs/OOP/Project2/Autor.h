//
// Created by Carlos Estrada on 23/02/18.
//

#ifndef PROJECT2_AUTOR_H
#define PROJECT2_AUTOR_H

#include <string>

class Autor
{
public:
    Autor();
    Autor(int idAutor, std::string nombre);

    int getIdAutor() {return idAutor;}
    std::string getNombre() {return nombre;}

    void setIdAutor(int idAutor);
    void setNombre(std::string nombre);

private:
    int idAutor;
    std::string nombre;
};

Autor::Autor()
{
    idAutor = 0;
    nombre = "No asignado";
}

Autor::Autor(int idAutor, std::string nombre)
{
    this->idAutor = idAutor;
    this->nombre = nombre;
}

void Autor::setIdAutor(int idAutor)
{
    this->idAutor = idAutor;
}

void Autor::setNombre(std::string nombre)
{
    this->nombre = nombre;
}

#endif //PROJECT2_AUTOR_H
