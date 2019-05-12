#include <iostream>
using namespace std;

int getData()
{
	int iNumber;
	cin >> iNumber;
	return iNumber;
}

int calculateThirdAge(int iFirstAge, int iSecondAge)
{
	int iDifference, iThirdAge;

	iDifference = iSecondAge - iFirstAge;
	iThirdAge = iSecondAge + iDifference;

	return iThirdAge;
}

void showData(int iResult)
{
	cout << iResult << endl;
}

int main()
{
	int iFirstAge, iSecondAge, iThirdAge;

	iFirstAge = getData();
	iSecondAge = getData();

	iThirdAge = calculateThirdAge(iFirstAge, iSecondAge);

	showData(iThirdAge);

	return 0;
}