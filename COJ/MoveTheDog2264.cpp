/*
NOT YET WORKING
Code created by Carlos Estrada
September 17, 2017
*/
#include <iostream>
using namespace std;

int getInt()
{
	int iNumber;
	cin >> iNumber;
	return iNumber;
}

char getCoordinate()
{
	char cCoordinate;
	cin >> cCoordinate;
	return cCoordinate;
}

void changePosition(int &iPosX, int &iPosY)
{
	char cDirection = getCoordinate();
	int AmountOfMov = getInt();

	switch(cDirection)
	{
		case 'E':
			iPosX = iPosX - AmountOfMov;
			break;

		case 'W':
			iPosX = iPosX + AmountOfMov;
			break;

		case 'S':
			iPosY = iPosY - AmountOfMov;
			break;

		case 'N':
			iPosY = iPosY + AmountOfMov;

		default:
		
			break;
	}
}

void calculateInitialPosition(int iPosX, int iPosY, int iAmount, 
							 int &iResultPositionX, int &iResultPositionY)
{
	for (int iCounter = 0; iCounter < iAmount; ++iCounter)
	{
		changePosition(iPosX, iPosY);

		iResultPositionX = iPosX;
		iResultPositionY = iPosY;
	}

}

void showResults(int iPosX, int iPosY)
{
	cout << iPosX << " " << iPosY << endl;
}

int main()
{
	//Declare variables
	int iSizeGridX, iSizeGridY;
	int iFinalPositionX, iFinalPositionY;
	int iInitialPositionX, iInitialPositionY;
	int iAmountOfInstructions = 0;

	//Get the grid size
	iSizeGridX = getInt();
	iSizeGridY = getInt();

	//Get the dog final postion
	iFinalPositionX = getInt();
	iFinalPositionY = getInt();

	iAmountOfInstructions = getInt();

	calculateInitialPosition(iFinalPositionX, iFinalPositionY,
							 iAmountOfInstructions, iInitialPositionX,
							 iInitialPositionY);

	showResults(iInitialPositionX, iInitialPositionY);

	return 0;
}