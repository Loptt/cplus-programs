#include <iostream> 
using namespace std;

int getData()
{
	int iNumber;
	cin >> iNumber;
	return iNumber;
}

bool isPrime(int iNumber)
{
	bool bNumIsPrime = true;
	int iRemainder = 0;
	int iCounter = 2;

	if (iNumber == 2)
	{
		bNumIsPrime = true;
	}
	do
 	{
 		iRemainder = iNumber % iCounter;

 		if (iRemainder == 0)
 		{
 			bNumIsPrime = false;
 		}
 		++iCounter;
 	} 
 	while (iCounter < iNumber || iRemainder != 0);
	
	 return bNumIsPrime;
}

void showPrime(bool bIsPrime)
{
	if (bIsPrime)
	{
		cout << "PRIME" << endl;
	}
	else
	{
		cout <<  "NOT PRIME" << endl;
	}
}

int main()
{
	int iNumber;
	bool bIsPrime;

	iNumber = getData();

	bIsPrime = isPrime(iNumber);

	showPrime(bIsPrime);

	return 0;
}