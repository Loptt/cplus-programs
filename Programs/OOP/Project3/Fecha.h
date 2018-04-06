
class Fecha
{
public:
    Fecha();
    Fecha(int, int, int);

    void setAa(int aa);
    void setMm(int mm);
    void setDd(int dd);

    Fecha operator+(int dias);

private:

    int aa, mm, dd;
};

Fecha::Fecha()
{
    aa = 2000;
    mm = 0;
    dd = 0;
}

Fecha::Fecha(int dd, int mm, int aa)
{
    this->dd = dd;
    this->mm = mm;
    this->aa = aa;
}

void Fecha::setAa(int aa)
{
    this->aa = aa;
}

void Fecha::setMm(int mm)
{
    this->mm = mm;
}

void Fecha::setDd(int dd)
{
    this->dd = dd;
}

Fecha Fecha::operator+(int dias)
{
    if ()
}
