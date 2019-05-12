/*
Creado por:
Carlos Estrada A01039919
José Guillermo Saldaña A01039888
*/

class Patio
{
  public:
    Patio();
    Patio(int,int);

    int getLargo() { return largo; }
    int getAncho() { return ancho; }

    void setLargo(int l) { largo = l; }
    void setAncho(int a) { ancho = a; }

    int caluclarArea();

  private:
    int largo, ancho;
};

Patio::Patio()
{
    largo = 0;
    ancho = 0;
}

Patio::Patio(int l, int a)
{
    largo = l;
    ancho = a;
}

int Patio::caluclarArea()
{
    return largo * ancho;
}


