#include <iostream>
using namespace std;

int getNumber()
{
	int iNumber;
	cin >> iNumber;
	return iNumber;
}

bool isTriangular(int iNumber)
{
	int iSum = 0;
	int iCounter = 0;

	bool bTester = false;

	while (iCounter < iNumber && iNumber != iSum)
	{

		iSum += iCounter;
		++iCounter;

		if (iNumber == iSum)
		{
			bTester = true;
		}
	}

	return bTester;
}

void showResult(bool bIsTrangular)
{
	if (bIsTrangular)
	{
		cout << "ES TRIANGULAR" << endl;
	}
	else
	{
		cout << "NO ES TRIANGULAR" << endl;
	}
}

int main()
{
	int iNumber = getNumber();

	bool bIsTrangular = isTriangular(iNumber);

	showResult(bIsTrangular);

	return 0;
}