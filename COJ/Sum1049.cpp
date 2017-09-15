/*
Code created by Carlos Estrada
No rights reserved OPEN FOR EVERYONE
Septmeber 15, 2017
*/

#include <iostream>
using namespace std;

//Function to read data from user
int getData()
{
	int iNumber;
	cin >> iNumber;
	return iNumber;
}

//Function to calculate sum given two cases
int sumAllIntegers(int iNumber)
{
	int iSum = 0;

	if (iNumber >= 0)
	{
		for (int iCounter = 0; iCounter <= iNumber; ++iCounter)
		{
			iSum +=	iCounter;
		}
	}
	else
	{
		for (int iCounter = 1; iCounter >= iNumber; --iCounter)
		{
			iSum += iCounter;
		}
	}

	return iSum;
}

//Function to output the result
void showResult(int iSum)
{
	cout << iSum << endl;
}

//Main function
int main()
{
	int iNumber, iSum;

	iNumber = getData();
	iSum = sumAllIntegers(iNumber);

	showResult(iSum);

	return 0;
}