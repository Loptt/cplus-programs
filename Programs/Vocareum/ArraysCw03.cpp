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
isInOrder
Function to check if arrays are in order
Parameters: The size and the array
return: whether they are in order
*/
bool isInOrder(int iSize, int iArrNumbers[])
{
	bool bIsInOrder = true;

	for (int iCounter = 1; iCounter < iSize; ++iCounter)
	{
		if (iArrNumbers[iCounter] < iArrNumbers[iCounter - 1])
		{
			bIsInOrder = false;
		}
	}

	return bIsInOrder;
}

/*
showResult
Function output the result
Parameters: the result in the processing function
return: nothing
*/
void showResult(bool bResult)
{
	cout << bResult << endl;
}

/*
main
Function to call other functions
Parameters: none
return: nothing
*/
int main()
{
	int iArrNumbers[200];
	
 	//Read inputs from user
	int iSize = readValues(iArrNumbers);

 	//Process the data
	bool bResult = isInOrder(iSize, iArrNumbers);

 	//Output the data
	showResult(bResult);

	return 0;
}