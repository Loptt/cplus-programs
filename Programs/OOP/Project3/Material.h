//
// Created by charles on 4/14/18.
//

#ifndef PROJECT3_MATERIAL_H
#define PROJECT3_MATERIAL_H

#include <iostream>
#include <string>
using namespace std;

class Material
{
public:
    Material() {idMaterial = 0; titulo = "-";}
    Material(int id, string tit) {idMaterial = id; titulo = tit;}

    void setTitulo(string titulo) {this->titulo = titulo;}
    void setIdMaterial(int idMaterial) {this->idMaterial = idMaterial; }

    int getIdMaterial() {return idMaterial;}
    string getTitulo() {return titulo;}

    virtual void muestra() = 0;
    virtual int cantidadDiasPrestamo() = 0;

protected:
    int idMaterial;
    string titulo;

};


#endif //PROJECT3_MATERIAL_H
