#include <iostream> 
using namespace std;

int getNumber()
{
	int iNumber;
	cout << "Enter a number" << endl;
	cin >> iNumber;
	return iNumber;
}

void showTimeTable(int iNumber)
{
	int iCounter = 1;
	int iResult = 0;

	while (iCounter <= 10)
	{
		iResult = iNumber * iCounter;
		cout << iNumber << " x " << iCounter++;
		cout << " = " << iResult << endl;
	}
}

int main()
{
	int iNumber = getNumber();

	showTimeTable(iNumber);

	return 0;
}