
/*
Carlos Estrada A01039919
Programming Fundamentals
October 17, 2017
ArraysHw02
*/

#include <iostream>
using namespace std;

/*
getNumbers
Function to get the input from the user
Parameters: The size of the array and the array itself
Return: nothing
*/
void getNumbers(int &iSize, int iArrNumbers[])
{
	cin >> iSize;

	for (int iCounter = 0; iCounter < iSize; ++iCounter)
	{
		cin >> iArrNumbers[iCounter];
	}
}

/*
calculateBiggest
Function to calculate the biggest number in the array
Parameters: The size of the array and the array itself
Return: The biggest number in the list
*/
int calculateBiggest(int iSize, int iArrNumbers[])
{
	int iBiggest = iArrNumbers[0];

	for (int iCounter = 1; iCounter < iSize; ++iCounter)
	{
		if (iArrNumbers[iCounter] > iBiggest)
		{
			iBiggest = iArrNumbers[iCounter];
		}
	}

	return iBiggest;
}

/*
showResult
Function to output the result
Parameters: The result of the processing function
Return: nothing
*/
void showResult(int iResult)
{
	cout << iResult << endl;
}

/*
main
Function to call other functions
Parameters: none
Return: nothing
*/
int main()
{
	//Declare variables
	int iArrNumbers[20];
	int iSize, iResult;

	//Get input from user
	getNumbers(iSize, iArrNumbers);

	//Process the data from the user
	iResult = calculateBiggest(iSize, iArrNumbers);

	//Output the result
	showResult(iResult);

	return 0;
}