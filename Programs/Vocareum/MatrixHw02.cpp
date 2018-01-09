#include <iostream>
using namespace std;

/*
getValues
Function to get the input from the user
Parameters: the matrix, the row amount and column amount
Return: nothing
*/
void getValues(int iMatValues[10][10], int &iRowNumber, int &iColNumber)
{
	cin >> iRowNumber >> iColNumber;

	for (int iRowIndex = 0; iRowIndex < iRowNumber; ++iRowIndex)
	{
		for (int iColIndex = 0; iColIndex < iColNumber; ++iColIndex)
		{
			cin >> iMatValues[iRowIndex][iColIndex];
		}
	}
}

/*
sumValues
Function to sum the edges of the matrix
Parameters: the matrix, the row amount and column amount
Return: the sum of the values
*/
int sumValues(int iMatValues[10][10], int iRowNumber, int iColNumber)
{
	int iSum = 0;

	for (int iRowIndex = 0; iRowIndex < iRowNumber; ++iRowIndex)
	{
		iSum += iMatValues[iRowIndex][0];
		iSum += iMatValues[iRowIndex][iColNumber-1];
	}

	for (int iColIndex = 1; iColIndex < iColNumber-1; ++iColIndex)
	{
		iSum += iMatValues[0][iColIndex];
		iSum += iMatValues[iRowNumber-1][iColIndex];
	}

	return iSum;
}

/*
showResult
Function to output the result
Parameters: The sum
Return: nothing
*/
void showResult(int iResult)
{
	cout << iResult << endl;
}	

/*
main
Function to call other functions
Parameters: tnone
Return: n0
*/
int main()
{
	//Declare variables
	int iMatValues[10][10], iRowNumber, iColNumber, iSum;

	//Get the input from the user
	getValues(iMatValues, iRowNumber, iColNumber);

	//Process the data to sum the result
	iSum = sumValues(iMatValues, iRowNumber, iColNumber);

	//Output the result
	showResult(iSum);
}