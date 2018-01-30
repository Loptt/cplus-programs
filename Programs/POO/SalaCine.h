//
// Created by charles on 29/01/18.
//

#ifndef HOMEWORK3_SALACINE_H
#define HOMEWORK3_SALACINE_H

#include <string>

class SalaCine
{
public:

    SalaCine();
    ~SalaCine();

    void setLugares(int);
    void setPelicula(std::string);

    int getLugares(){ return lugares; };
    std::string getPelicula(){ return pelicula; };

    void compraBoleto(int);

private:

    int lugares;
    std::string pelicula;
};

SalaCine::SalaCine()
{
    lugares = 0;
    pelicula = " ";
}

SalaCine::~SalaCine()
{

}

void SalaCine::setPelicula(std::string pelicula)
{
    this->pelicula = pelicula;
}

void SalaCine::setLugares(int lugares)
{
    this->lugares = lugares;
}

void SalaCine::compraBoleto(int lugaresAComprar)
{
    lugares -= lugaresAComprar;
}

#endif //HOMEWORK3_SALACINE_H
