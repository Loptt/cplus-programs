/**
@progName Dados
@desc Programa que tira 2 dados 200 veces y registra su suma
@author Carlos Estrada
@Date 16 de enero del 2018
*/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

/**
@funcName generateRandomDices
@desc Funcion que genera el tirar dos dados
@param Dos enteros que representan la cara que sale
@return Funcion tipo void, los valores se pasan como referencia
*/
void generateRandomDices(int &iDice1, int &iDice2)
{
    iDice1 = rand() % 6 + 1;
    iDice2 = rand() % 6 + 1;
}

/**
@funcName findBiggestAndSmallest
@desc Del arreglo de valores resultantes, encuentra las cantidades mas grandes y mas chicas
@param El arreglo con los valores, un entero representando el mayor y otro con el menor
@return Funcion tipo void, los valores se pasan como referencia
*/
void findBiggestAndSmallest(int iValueAmounts[], int &iBiggest, int &iSmallest)
{
    int iBigAmount = 0;
    int iSmallAmount = 201;
    for (int iCounter = 2; iCounter < 13; ++iCounter)
    {
        if (iValueAmounts[iCounter] > iBigAmount)
        {
            iBiggest = iCounter;
            iBigAmount = iValueAmounts[iCounter];
        }

        if (iValueAmounts[iCounter] < iSmallAmount)
        {
            iSmallest = iCounter;
            iSmallAmount = iValueAmounts[iCounter];
        }    
    }
}

/**
@funcName displayDiceData
@desc Funcion para desplegar en la consola los resultados
@param El arreglo con los valores, un entero representando el mayor y otro con el menor
@return Nada
*/
void displayDiceData(int iValueAmounts[], int iBiggest, int iSmallest)
{
    for (int iCounter = 2; iCounter < 13; ++iCounter)
    {
        cout << setw(4) << iCounter << " |";

        for (int iCounter2 = 0; iCounter2 < iValueAmounts[iCounter]; ++iCounter2)
        {
            cout << '*';
        }

        cout << endl;
    }

    cout << endl;
    cout << "El valor que tiene mas probabilidad de salir es " << iBiggest << endl;
    cout << "El valor que tiene menos probabilidad de salir es " << iSmallest << endl;
}

/**
@funcName main
@desc Funcion principal que llama a otras funciones
@param Nada
@return 0, el programa funciona exitosamente
*/
int main()
{
    int iDice1 = 0;
    int iDice2 = 0;
    int iSum = 0;

    int iValueAmounts[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};

    int iBiggest = 0, iSmallest = 201;

    srand(time(NULL));

    for (int iCounter = 0; iCounter < 200; ++iCounter)
    {
        generateRandomDices(iDice1, iDice2);
        iSum = iDice1 + iDice2;

        ++iValueAmounts[iSum];
    }

    findBiggestAndSmallest(iValueAmounts, iBiggest, iSmallest);

    displayDiceData(iValueAmounts, iBiggest, iSmallest);


    return 0;
}