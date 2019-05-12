/*
Carlos Estrada A01039919
Programming Fundamentals
October 13, 2017
*/
#include <iostream>
using namespace std;

/*
readValues
Function to read all values in the array and the size
Parameters: The array to store values
return: The size of the array
*/
int readValues(int iArrNumbers[])
{
	int iSize;
	cin >> iSize;

	for (int iCounter = 0; iCounter < iSize; ++iCounter)
	{
		cin >> iArrNumbers[iCounter];
	}

	return iSize;
}

/*
sumNumbers
Function to sum all elements in the array
Parameters: The size and the array
return: the sum of the elements
*/
int sumNumbers(int iSize, int iArrNumbers[])
{
	int iSum = 0;

	for (int iCounter = 0; iCounter < iSize; ++iCounter)
	{
		iSum += iArrNumbers[iCounter];
	}

	return iSum;
}

/*
showResult
Function output the result
Parameters: the result in the processing function
return: nothing
*/
void showResult(int iResult)
{
	cout << iResult << endl;
}

/*
main
Function to call other functions
Parameters: none
return: nothing
*/
int main()
{
	int iArrNumbers[20];
	
 	//Read inputs from user
	int iSize = readValues(iArrNumbers);

 	//Process the data
	int iResult = sumNumbers(iSize, iArrNumbers);

 	//Output the data
	showResult(iResult);

	return 0;
}