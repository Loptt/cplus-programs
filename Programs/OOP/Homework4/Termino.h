#include <iostream>
#include "Fraccion.h"

class Termino
{
public:
	Termino();
	Termino(Fraccion, char, int);

	void setCoeficiente(Fraccion);
	void setVariable(char);
	void setExponente(int);

	Fraccion getCoeficiente() { return coeficiente; };
	char getVariable() { return variable; };
	int getExponente() { return exponente; };

	void muestra();

private:
	Fraccion coeficiente;
	char variable;
	int exponente;
};

Termino::Termino()
{
	Fraccion coeficiente(1,1);
	this->coeficiente = coeficiente;
	variable = 'x';
	exponente = 1;
}

Termino::Termino(Fraccion coeficiente, char variable, int exponente)
{
	this->coeficiente = coeficiente;
	this->variable = variable;
	
	if (exponente < 0)
	{
		exponente = 1;
	}

	this->exponente = exponente;
}

void Termino::setCoeficiente(Fraccion coeficiente)
{
	this->coeficiente = coeficiente;
}

void Termino::setVariable(char variable)
{
	this->variable = variable;
}

void Termino::setExponente(int exponente)
{
	if (exponente < 0)
	{
		exponente = 1;
	}

	this->exponente = exponente;
}

void Termino::muestra()
{
	coeficiente.muestra();
	std::cout << variable;

	if (exponente != 1)
	{
		std::cout << '^' << exponente;
	}
}