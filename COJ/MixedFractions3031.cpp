/*
Code created by Carlos Estrada
September 17, 2017
*/

#include <iostream>
#include <cstdio>
using namespace std;

int getNumber()
{
	int iNumber;
	scanf("%d", &iNumber);
	return iNumber;
}

int calculateWhole(int iNominator, int iDenominator)
{
	int iWhole = iNominator / iDenominator;
	return iWhole;
}

int calculateNewNom(int iNominator, int iDenominator)
{
	int iModule = iNominator % iDenominator;
	return iModule;
}

void showData(int iWhole, int iNominator, int iDenominator)
{
	char sSpace[] = "";
	char sSlash[] = "/";
	printf("%d %d %s %d \n", iWhole, iNominator, sSlash, iDenominator);
}

void calculateMixed(int iNominator, int iDenominator, int &iNewNom,
	                int &iWhole)
{
	
	iNewNom = calculateNewNom(iNominator, iDenominator);
	iWhole  = calculateWhole(iNominator, iDenominator);
}

int main()
{
	int iNominator, iDenominator;
	int iNewNom, iWhole;

	iNominator = getNumber();
	iDenominator = getNumber();

	while (iNominator != 0 && iDenominator != 0)
	{
		calculateMixed(iNominator, iDenominator, iNewNom, iWhole);

		showData(iWhole, iNewNom, iDenominator);

		iNominator = getNumber();
		iDenominator = getNumber();
	}

	return 0;
}