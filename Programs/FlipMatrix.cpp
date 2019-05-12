#include <iostream>
using namespace std;

void getData(int iMatValues[10][10], int &iRowSize, int &iColSize)
{
	cin >> iRowSize >> iColSize;

	for (int iRowIndex = 0; iRowIndex < iRowSize; ++iRowIndex)
	{
		for (int iColIndex = 0; iColIndex < iColSize; ++iColIndex)
		{
			cin >> iMatValues[iRowIndex][iColIndex];
		}
	}
}

void switchValues(int &iNumber1, int &iNumber2)
{
	int iStorage;
	iStorage = iNumber1;
	iNumber1 = iNumber2;
	iNumber2 = iStorage;
}

void flipHorizontalMatrix(int iMatValues[10][10], int iRowSize, int iColSize)
{
	for (int iRowIndex = 0; iRowIndex < iRowSize; ++iRowIndex)
	{
		for (int iColIndex = 0; iColIndex < iColSize/2; ++iColIndex)
		{
			switchValues(iMatValues[iRowIndex][iColIndex], iMatValues[iRowIndex][iColSize-1-iColIndex]);
		}	
	}
}

void flipVerticalMatrix(int iMatValues[10][10], int iRowSize, int iColSize)
{	
	for (int iRowIndex = 0; iRowIndex < iRowSize/2; ++iRowIndex)
	{
		for (int iColIndex = 0; iColIndex < iColSize; ++iColIndex)
		{
			switchValues(iMatValues[iRowIndex][iColIndex], iMatValues[iRowSize -1 -iRowIndex][iColIndex]);
		}	
	}
}

void showData(int iMatValues[10][10], int iRowSize, int iColSize)
{
	cout << endl;

	for (int iRowIndex = 0; iRowIndex < iRowSize; ++iRowIndex)
	{
		for (int iColIndex = 0; iColIndex < iColSize; ++iColIndex)
		{
			cout << iMatValues[iRowIndex][iColIndex] << " ";
		}

		cout << endl;
	}
}

int main()
{
	int iRowSize, iColSize, iMatValues[10][10], iMatValuesVertical[10][10], iMatValuesHorizontal[10][10];

	getData(iMatValues, iRowSize, iColSize);

	flipHorizontalMatrix(iMatValues, iRowSize, iColSize);

	showData(iMatValues, iRowSize, iColSize);

	return 0;
}