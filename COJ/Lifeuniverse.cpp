#include <iostream>
using namespace std;

int getData()
{
	int iNumber;
	cin >> iNumber;
	return iNumber;
}

void printNumber(int iNumber)
{
	cout << iNumber << endl;
}

int main()
{
	int iNumber;
	iNumber = getData();

	while (iNumber != 42)
	{
		printNumber(iNumber);
		iNumber = getData();
	}
	return 0;
}