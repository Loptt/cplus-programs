//
// Created by charles on 29/01/18.
//

#ifndef HOMEWORK3_ESFERA_H
#define HOMEWORK3_ESFERA_H

class Esfera
{
public:

    Esfera();
    ~Esfera();

    void setRadio(float radio);
    float getRadio();

    float calcArea();
    float calcVolum();

private:
    float radio;
};

Esfera::Esfera()
{
    radio = 1;
}

Esfera::~Esfera()
{

}

void Esfera::setRadio(float radio)
{
    this->radio = radio;
}

float Esfera::getRadio()
{
    return radio;
}

float Esfera::calcArea()
{
    return 4.0 * 3.141592 * radio * radio;
}

float Esfera::calcVolum()
{
    return (4.0 * 3.141592 * radio * radio * radio)/3.0;
}

#endif //HOMEWORK3_ESFERA_H
