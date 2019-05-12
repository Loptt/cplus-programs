//
// Created by charles on 4/14/18.
//

#ifndef PROJECT3_LIBRO_H
#define PROJECT3_LIBRO_H

#include "Material.h"

class Libro : public Material
{
public:
    Libro() : Material() {numPag = 0; autor = "-";};
    Libro(int id, string tit, int num, string aut);

    void muestra() override;
    int cantidadDiasPrestamo() override;

    void setNumPag(int numPag) {this->numPag = numPag;}
    void setAutor(string autor) {this->autor = autor;}

    int getNumPag() {return numPag;}
    string getAutor() {return autor;}

private:
    int numPag;
    string autor;
};

Libro::Libro(int id, string tit, int num, string aut) : Material(id,tit)
{
    numPag = num;
    autor = aut;
}

void Libro::muestra()
{
    cout << "ID de libro: " << idMaterial << endl;
    cout << "Titulo de libro: " << titulo << endl;
    cout << "Numero de paginas: " << numPag << endl;
    cout << "Autor: " << autor << endl;
}

int Libro::cantidadDiasPrestamo()
{
    return 10;
}


#endif //PROJECT3_LIBRO_H
