
/*
Carlos Estrada A01039919
Programming Fundamentals
October 17, 2017
ArraysHw02
*/

#include <iostream>
using namespace std;

/*
getLetters
Function to get the input from the user
Parameters: The size of the array and the array itself
Return: nothing
*/
void getLetters(int &iSize, char cArrLetters[])
{
	cin >> iSize;

	for (int iCounter = 0; iCounter < iSize; ++iCounter)
	{
		cin >> cArrLetters[iCounter];
	}
}

/*
hasExclamation
Function to check if the array contains an exclamation mark
Parameters: The size of the array and the array itself
Return: True or false result if the sign is present
*/
bool hasExclamation(int iSize, char cArrLetters[])
{
	bool bHasExclamation = false;

	for (int iCounter = 0; iCounter < iSize; ++iCounter)
	{
		if (cArrLetters[iCounter] == '!')
		{
			bHasExclamation = true;
		}
	}

	return bHasExclamation;
}

/*
showResult
Function to output the result
Parameters: The result of the processing function
Return: nothing
*/
void showResult(int bResult)
{
	cout << bResult << endl;
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
	char cArrLetters[50];
	int iSize;
	bool bHasExclamation;
	//Get input from user
	getLetters(iSize, cArrLetters);

	//Process the data from the user
	bHasExclamation = hasExclamation(iSize, cArrLetters);

	//Output the result
	showResult(bHasExclamation);

	return 0;
}