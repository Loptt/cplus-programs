#include <iostream> 
using namespace std;

const bool bTestCase = true;

int getNumber()
{
	if (bTestCase)
	{
		cout << "Enter Number:" << endl;
	}
	int iNumber;
	cin >> iNumber;
	return 0;
}

int sumSquares(int iFirstNumber, int iSecondNumber)
{
	int iSum = ( iFirstNumber * iFirstNumber ) + (iSecondNumber * iSecondNumber);
	return iSum;
}

int square(int iNumber)
{
	int iSquared = iNumber * iNumber;
	return iSquared;
}

bool isPythagorean(int iFirstNumber, int iSecondNumber,int iThirdNumber)
{
	bool bIsPythagorean = false;

	if (square(iFirstNumber) == sumSquares(iSecondNumber, iThirdNumber))
	{
		bIsPythagorean = true;
	}
	else
	{
		if (square(iSecondNumber) == sumSquares(iThirdNumber, iFirstNumber))
		{
			bIsPythagorean = true;	
		}
		else
		{
			if (square(iThirdNumber) == sumSquares(iSecondNumber, iFirstNumber))
			{
				bIsPythagorean = true;
			}
		}
	}

	return bIsPythagorean;
}

void showResult(bool bIsPythagorean)
{
	if (bIsPythagorean)
	{
		cout << "right" << endl;
	}
	else
	{
		cout << "wrong" << endl;
	}
}

int main()
{
	int iFirstNumber = 1;
	int iSecondNumber = 1;
	int iThirdNumber = 1;

	bool bIsPythagorean = false;

	while (iFirstNumber != 0 || iSecondNumber != 0 || iThirdNumber != 0)
	{
		iFirstNumber = getNumber();
		iSecondNumber = getNumber();
		iThirdNumber = getNumber();

		if (iFirstNumber != 0 || iSecondNumber != 0 || iThirdNumber != 0)
		{
			bIsPythagorean = isPythagorean(iFirstNumber, iSecondNumber, iThirdNumber);
			showResult(bIsPythagorean);
		}
	}

	return 0;
}