//
// Created by Carlos Estrada on 2/25/18.
//

#ifndef PROJECT2_FECHA_H
#define PROJECT2_FECHA_H


class Fecha
{
public:
    Fecha();

    int getDd() const {return dd;}
    int getMm() const {return mm;}
    int getAa() const {return aa;}

    void setDd(int dd);
    void setMm(int mm);
    void setAa(int aa);

    void setFecha(int dd, int mm, int aa);

private:
    int dd;
    int mm;
    int aa;

};

Fecha::Fecha()
{
    dd = 1;
    mm = 1;
    aa = 0;
}


void Fecha::setDd(int dd)
{
    this->dd = dd;
}

void Fecha::setMm(int mm)
{
    this->mm = mm;
}

void Fecha::setAa(int aa)
{
    this->aa = aa;
}

void Fecha::setFecha(int dd, int mm, int aa)
{
    this->dd = dd;
    this->mm = mm;
    this->aa = aa;
}


#endif //PROJECT2_FECHA_H
