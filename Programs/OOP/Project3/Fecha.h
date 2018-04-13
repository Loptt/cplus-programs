

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
    friend Fecha operator + (Fecha f1, int dias);

    // como friend la sobrecarga del operador >>
    // que lee 3 valores enteros: dia, mes, anio con 4 digitos
    friend istream operator >> ();

    // como friend la sobrecarga del operador <<
    // que muestra la fecha en el formato dd/mm/aaaa
    // no incluyas espacios ni enter
    friend ostream operator << ();


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

    int calculaMaxDias();
    bool esBiciesto();
};

bool Fecha::esBiciesto()
{
    return (!(aa % 4) && aa % 100 && !(aa % 400));
}

int Fecha::calculaMaxDias()
{
    switch (mm)
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

            if(esBiciesto())
            {
                return 29;
            }

            return 28;
            break;

        default:

            break;
    }
}

bool friend operator==(Fecha f1, Fecha f2)
{
    return f1.aa == f2.aa && f1.mm == f2.mm && f1.dd == f2.dd;
}

bool operator>(Fecha f1, Fecha f2)
{
    return f1.aa > f2.aa && f1.mm > f2.mm && f1.dd > f2.dd;
}

bool operator>=(Fecha f1, Fecha f2)
{
    return f1 > f2 || f1 == f2;
}

bool operator<(Fecha f1, Fecha f2)
{
    return !(f1>f2);
}

bool operator<=(Fecha f1, Fecha f2)
{
    return f1 < f2 || f1 == f2;
}

Fecha operator+(Fecha f1, int diasAgregar)
{
    int maxDias = f1.calculaMaxDias();

    int diasSobrantes;

    do
    {
        diasSobrantes = diasAgregar - maxDias;

        if (diasSobrantes > 0 )
        {
            if (++f1.mm > 12)
            {
                ++f1.aa;
                f1.mm = 1;
            }
        }

        maxDias = f1.calculaMaxDias();

    }
    while (diasSobrantes > 0);

    return f1;


}
