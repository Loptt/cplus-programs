#include <iostream>
using namespace std;

class Fecha
{
    // como friend la sobrecarga del operador >
    friend bool operator > (Fecha f1, Fecha f2);

    // como friend la sobrecarga del operador >=
    friend bool operator >= (Fecha f1, Fecha f2);

    // como friend la sobrecarga del operador <
    friend bool operator < (Fecha f1, Fecha f2);

    // como friend la sobrecarga del operador <=
    friend bool operator <= (Fecha f1, Fecha f2);

    // como friend la sobrecarga del operador ==
    friend bool operator == (Fecha f1, Fecha f2);

    // como friend la sobrecarga del operador +
    // que recibe como parametro una fecha y un numero entero
    // que representa una cantidad de dias y regresa
    // la fecha a la que se le agregaron los dias indicados
    friend Fecha operator + (Fecha f1, int diasAgregar);

    // como friend la sobrecarga del operador >>
    // que lee 3 valores enteros: dia, mes, anio con 4 digitos
    friend istream& operator >> (istream &is, Fecha &f1);

    // como friend la sobrecarga del operador <<
    // que muestra la fecha en el formato dd/mm/aaaa
    // no incluyas espacios ni enter
    friend ostream& operator << (ostream &os, Fecha f1);


public:
    Fecha() { dd = 0; mm = 0; aa = 0; }
    Fecha(int d, int m, int a) { dd = d; mm = m; aa = a; }

    int getDia() { return dd; }
    int getMes() { return mm; }
    int getAnio() { return aa; }

    void setFecha(int d, int m, int a) { dd = d; mm = m; aa = a; }

private:
    // atributos
    int dd, mm, aa;

    int calculaMaxDias(int, int);
    bool esBiciesto(int);
    bool esBiciesto();

    string nombreMes();
};

bool Fecha::esBiciesto(int anio)
{
    return (!(anio % 4) || (anio % 100 && !(anio % 400)));
}

bool Fecha::esBiciesto()
{
    return (!(aa % 4) || (aa % 100 && !(aa % 400)));
}

string Fecha::nombreMes()
{
    switch(mm)
    {
        case 1:
            return "Ene";

        case 2:
            return "Feb";

        case 3:
            return "Mar";

        case 4:
            return "Abr";

        case 5:
            return "May";

        case 6:
            return "Jun";

        case 7:
            return "Jul";

        case 8:
            return "Ago";

        case 9:
            return "Sep";

        case 10:
            return "Oct";

        case 11:
            return "Nov";

        case 12:
            return "Dic";
    }
}

int Fecha::calculaMaxDias(int mes, int anio)
{
    switch (mes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:

            return 31;

        case 4:
        case 6:
        case 9:
        case 11:
            return 30;

        case 2:

            if(esBiciesto(anio))
            {
                return 29;
            }

            return 28;
            break;

        default:

            break;
    }
}

bool operator==(Fecha f1, Fecha f2)
{
    return (f1.aa == f2.aa && f1.mm == f2.mm && f1.dd == f2.dd);
}

bool operator>(Fecha f1, Fecha f2)
{
    if (f1.aa > f2.aa)
    {
        return true;
    }
    else
    {
        if (f1.aa == f2.aa)
        {
            if (f1.mm > f2.mm)
            {
                return true;
            }
            else
            {
                if (f1.mm == f2.mm)
                {
                    if (f1.dd > f2.dd)
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool operator>=(Fecha f1, Fecha f2)
{
    return (f1 > f2 || f1 == f2);
}

bool operator<(Fecha f1, Fecha f2)
{
    return !(f1>=f2);
}

bool operator<=(Fecha f1, Fecha f2)
{
    return (f1 < f2 || f1 == f2);
}

Fecha operator+(Fecha f1, int diasAgregar)
{
    int maxDias = f1.calculaMaxDias(f1.mm, f1.aa);
    int diaActual = f1.dd;
    int mesActual = f1.mm;
    int anioActual = f1.aa;

    int diasSobrantes = 0;

    if (diasAgregar + diaActual > maxDias)
    {
        if(++mesActual > 12)
        {
            ++anioActual;
            mesActual = 1;
        }

        diasSobrantes = diasAgregar + diaActual - maxDias;
    }
    else
    {
        diasSobrantes = diasAgregar + diaActual;
    }

    Fecha resultado(diasSobrantes, mesActual, anioActual);

    return resultado;


}

istream &operator>>(istream &is, Fecha &f1)
{
    is >> f1.dd;
    is >> f1.mm;
    is >> f1.aa;

    return is;
}

ostream &operator<<(ostream &os, Fecha f1)
{
    os << f1.dd << "/" << f1.nombreMes() << "/" << f1.aa;
    return os;
}
