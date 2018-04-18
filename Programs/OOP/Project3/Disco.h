//
// Created by charles on 4/14/18.
//

#ifndef PROJECT3_DISCO_H
#define PROJECT3_DISCO_H

#include "Material.h"

class Disco :public Material
{
public:
    Disco() : Material() {duracion = 0;}
    Disco(int id, string tit, int dur);

    void muestra() override;
    int cantidadDiasPrestamo() override;

    void setDuracion(int duracion) {this->duracion = duracion;}

    int getDuracion() {return duracion;}

private:
    int duracion;
};

Disco::Disco(int id, string tit, int dur) : Material(id,tit)
{
    duracion = dur;
}

void Disco::muestra()
{
    cout << "ID del Disco: " << idMaterial << endl;
    cout << "Titulo del Disco: " << titulo << endl;
    cout << "Duracion: " << duracion << " min."<<endl;
}

int Disco::cantidadDiasPrestamo()
{
    return 3;
}


#endif //PROJECT3_DISCO_H
