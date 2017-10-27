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
finfPositionOf5
Function to find the positions where ther is a 5
Parameters: The size , the array and th new array
return: the size of the new array
*/
int findPositionOf5(int iSize, int iArrNumbers[], int iArrPositionOf5[])
{
	int iCountOf5 = 0;
	for (int iCounter = 0; iCounter < iSize; ++iCounter)
	{
		if (iArrNumbers[iCounter] == 5)
		{
			iArrPositionOf5[iCountOf5] = iCounter;
			++iCountOf5;
		}
	}

	return iCountOf5;
}

/*
showResult
Function output the result
Parameters: the result in the processing function
return: nothing
*/
void showResult(int iArrPositionOf5[], int iCountOf5)
{
	if (iCountOf5 == 0)
	{
		cout << -1;
	}
	else
	{
		for (int iCounter = 0; iCounter < iCountOf5; ++iCounter)
		{
			cout << iArrPositionOf5[iCounter] << " " ;
		}
	}
 		
 	cout << endl;
}

/*
main
Function to call other functions
Parameters: none
return: nothing
*/
int main()
{
	int iArrNumbers[200], iArrPositionOf5[200];
	int iCountOf5 = 0;
	
 	//Read inputs from user
	int iSize = readValues(iArrNumbers);

 	//Process the data
	iCountOf5 = findPositionOf5(iSize, iArrNumbers, iArrPositionOf5);

 	//Output the data
	showResult(iArrPositionOf5, iCountOf5);

	return 0;
}