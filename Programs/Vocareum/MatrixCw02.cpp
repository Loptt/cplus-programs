#include <iostream>
using namespace std;

/*
getValues
Function to get the values of the matrix and the size
Parameters: the matrix, the row and column size
return: nothing
*/
void getValues(int iMatValues[20][20], int &iRowsNumber, int &iColNumber)
{
	cin >> iRowsNumber >> iColNumber;

	for (int iRowIndex = 0; iRowIndex < iRowsNumber; ++iRowIndex)
	{
		for (int iColIndex = 0; iColIndex < iColNumber; ++iColIndex)
		{
			cin >> iMatValues[iRowIndex][iColIndex];
		}
	}
}

/*
findBiggest
Function to find the biggest value in the matrix
Parameters: the matrix, the row and column size
return: the biggest number
*/
int findBiggest(int iMatValues[20][20], int iRowsNumber, int iColNumber)
{
	int iBiggest = -999;

	for (int iRowIndex = 0; iRowIndex < iRowsNumber; ++iRowIndex)
	{
		for (int iColIndex = 0; iColIndex < iColNumber; ++iColIndex)
		{
			if (iMatValues[iRowIndex][iColIndex] > iBiggest)
			{
				iBiggest = iMatValues[iRowIndex][iColIndex];
			}
		}
	}

	return iBiggest;
}

/*
showData
Function to output the result
Parameters: the result obtained
return: nothing
*/
void showData(int iResult)
{
	cout << iResult << endl;
}

/*
main
Function to call other functions
Parameters: nothing
return: 0
*/
int main()
{
	//Declare variables
	int iMatValues[20][20], iRowsNumber, iColNumber;

	//Get the input
	getValues(iMatValues, iRowsNumber, iColNumber);

	//Process data to find biggest
	int iBiggest = findBiggest(iMatValues, iRowsNumber, iColNumber);

	//Output the result
	showData(iBiggest);
}