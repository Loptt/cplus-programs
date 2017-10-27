#include <iostream>
using namespace std;

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

int howManyEven(int iSize, int iArrNumbers[])
{
	int iNumberOfEven = 0;

	for (int iCounter = 0; iCounter < iSize; ++iCounter)
	{
		if (iArrNumbers[iCounter] % 2 == 0)
		{
			iNumberOfEven++;
		}
	}

	return iNumberOfEven;
}

void showResult(int iResult)
{
	cout << iResult << endl;
}

int main()
{
	int iArrNumbers[20];

	int iSize = readValues(iArrNumbers);

	int iResult = howManyEven(iSize, iArrNumbers);

	showResult(iResult);

	return 0;
}