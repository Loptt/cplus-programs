#include <iostream>
using namespace std;

/*
getValues
Function 
*/
void getValues(int iMatValues[20][20], int &iSize)
{
	cin >> iSize;

	for (int iRowIndex = 0; iRowIndex < iSize; ++iRowIndex)
	{
		for (int iColIndex = 0; iColIndex < iSize; ++iColIndex)
		{
			cin >> iMatValues[iRowIndex][iColIndex];
		}
	}
}

void rotateMatrix(int iMatValues[20][20], int iMatValuesRotated[20][20], int iSize)
{
	for (int iRowIndex = 0; iRowIndex < iSize; ++iRowIndex)
	{
		for (int iColIndex = 0; iColIndex < iSize; ++iColIndex)
		{
			iMatValuesRotated[iRowIndex][iColIndex] = iMatValues[iColIndex][iSize - iRowIndex - 1];	
		}
	}
}

void printMatrix(int iMatValuesRotated[20][20], int iSize)
{
	for (int iRowIndex = 0; iRowIndex < iSize; ++iRowIndex)
	{
		for (int iColIndex = 0; iColIndex < iSize; ++iColIndex)
		{
			cout << iMatValuesRotated[iRowIndex][iColIndex] << " ";
		}

		cout << endl;
	}
}

int main()
{
	int iMatValues[20][20], iMatValuesRotated[20][20], iMatValuesRotatedAgain[20][20];
	int iSize;

	getValues(iMatValues, iSize);

	rotateMatrix(iMatValues, iMatValuesRotated, iSize);

	rotateMatrix(iMatValuesRotated, iMatValuesRotatedAgain, iSize);

	printMatrix(iMatValuesRotatedAgain, iSize);

	return 0;
}