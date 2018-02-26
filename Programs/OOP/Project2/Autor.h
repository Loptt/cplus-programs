//
// Created by charles on 23/02/18.
//

#ifndef PROJECT2_AUTOR_H
#define PROJECT2_AUTOR_H

#include <string>

class Autor
{
public:
    Autor();

    int getIdAutor();
    std::string getNombre();

    void setIdAutor(int idAutor);
    void setNombre(const std::string &nombre);

private:
    int idAutor;
    std::string nombre;
};

int Autor::getIdAutor()
{
    return idAutor;
}

std::string Autor::getNombre()
{
    return nombre;
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
