#include <iostream>
using namespace std;
#include "Termino.h"

double calcularValor(Termino termino, double valor)
{
	double acumulado = valor;

	for (int iCounter = 0; iCounter < termino.getExponente()-1; ++iCounter)
	{
		acumulado *= valor;
	}

	return acumulado * termino.getCoeficiente().calcValorReal();
}

int main()
{
	Termino polinomio[8];
	int cantidad, numerador, denominador, exponente;
	double valor, suma;
	char variable;

	Fraccion fraccion;

	cout << "Cuantos terminos tendra el polinomio?: ";
	cin >> cantidad;

	cout << "Que letra se usara para expresar el polinomio?: ";
	cin >> variable;
	cout << endl;

	for (int iCounter = 0; iCounter < cantidad; ++iCounter)
	{
		cout << "Introduce el numerador del termino " << iCounter+1 << ": ";
		cin >> numerador;
		fraccion.setNum(numerador);

		cout << "Introduce el denominador del termino " << iCounter+1 << ": ";
		cin >> denominador;
		fraccion.setDen(denominador);

		polinomio[iCounter].setCoeficiente(fraccion);

		cout << "Introduce el exponente del termino " << iCounter+1 << ": ";
		cin >> exponente;
		polinomio[iCounter].setExponente(exponente);

		polinomio[iCounter].setVariable(variable);

		cout << endl;
	}

	cout << "Polinomio introducido: " << endl;

	for (int iCounter = 0; iCounter < cantidad; ++iCounter)
	{
		if (polinomio[iCounter].getCoeficiente().getNum() > 0)
		{
			cout << '+';
			polinomio[iCounter].muestra(); 
			cout << ' ';
		}
		else
		{
			polinomio[iCounter].muestra();
			cout << ' ';
		}
	}

	cout << endl << "Introduce un valor para evaluar el polinomio: ";
	cin >> valor;

	for (int iCounter = 0; iCounter < cantidad; ++iCounter)
	{
		suma += calcularValor(polinomio[iCounter], valor); 
	}

	cout << "El valor del polinomio es: " << suma << endl;

	return 0;
}