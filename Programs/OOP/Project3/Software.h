//
// Created by charles on 4/15/18.
//

#ifndef PROJECT3_SOFTWARE_H
#define PROJECT3_SOFTWARE_H

#include "Material.h"

class Software : public Material
{
public:
    Software() : Material() {sistemaOper = "-";}
    Software(int id, string tit, string);

    void muestra() override;
    int cantidadDiasPrestamo() override;

    void setSistemaOper(string sistemaOper) {this->sistemaOper= sistemaOper;}

    string getSistemaOper() {return sistemaOper;}

private:
    string sistemaOper;
};

Software::Software(int id, string tit, string sis) : Material(id,tit)
{
    sistemaOper = sis;
}

void Software::muestra()
{
    cout << "ID del software: " << idMaterial << endl;
    cout << "Titulo del software: " << titulo << endl;
    cout << "Sistema operativo: " << sistemaOper << endl;
}

int Software::cantidadDiasPrestamo()
{
    return 1;
}



#endif //PROJECT3_SOFTWARE_H
