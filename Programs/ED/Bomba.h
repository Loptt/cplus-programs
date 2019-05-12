/*
Creado por:
Carlos Estrada A01039919
José Guillermo Saldaña A01039888
*/

#include <string>
#include <iostream>
using namespace std;

class Bomba
{
  public:
    Bomba();
    Bomba(string marca, int capacidad);

    string getMarca();
    int getCapacidad();
    void setMarca(string marca);
    void setCapacidad(int cap);
    void calcularRiego(int temp, int area);
    void desplegarRiego(int litros);

  private:
    string marca;
    int capacidad;
};

Bomba::Bomba()
{
    marca = "";
    capacidad = 0;
}

Bomba::Bomba(string marca, int capacidad)
{
    this->marca = marca;
    this->capacidad = capacidad;
}

string Bomba::getMarca()
{
    return marca;
}

int Bomba::getCapacidad()
{
    return capacidad;
}

void Bomba::setMarca(string marca)
{
    this->marca = marca;
}

void Bomba::setCapacidad(int cap)
{
    this->capacidad = cap;
}

void Bomba::calcularRiego(int temp, int area)
{
    int litros;
    if (temp >= 30)
    {
        litros = 2 * (area * 10);
    }
    else if (temp < 0)
    {
        litros = 0;
    }
    else
    {
        litros = area * 10;
    }

    desplegarRiego(litros);
}

void Bomba::desplegarRiego(int litros)
{
    cout << "Se liberarán " << litros << " litros de agua" << endl;
}