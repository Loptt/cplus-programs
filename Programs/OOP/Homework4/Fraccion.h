class Fraccion
{
public:
    Fraccion();
    Fraccion(int, int);
    ~Fraccion();

    void setNum(int);
    void setDen(int);

    int getNum();
    int getDen();

    double calcValorReal();
    void muestra();

private:
    int num;
    int den;

};

Fraccion::Fraccion()
{
    num = 1;
    den = 1;
}

Fraccion::Fraccion(int num, int den)
{
    this->num = num;
    this->den= den;

    if (den < 0)
    {
        num *= -1;
        den *= -1;
    }
}

Fraccion::~Fraccion()
{

}

void Fraccion::setNum(int num)
{
    this->num = num;
}

void Fraccion::setDen(int den)
{
    this->den = den;

    if (den < 0)
    {
        num *= -1;
        den *= -1;
    }
}

int Fraccion::getNum()
{
    return num;
}

int Fraccion::getDen()
{
    return den;
}

double Fraccion::calcValorReal()
{
    return (double)num / den;
}

void Fraccion::muestra()
{
    std::cout << num << "/" << den;
}