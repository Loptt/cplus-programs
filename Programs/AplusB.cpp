#include <iostream>
#include <string>
using namespace std;

int readData(string sMessage)
{
	int iNumber;
	cout << "Please enter " << sMessage << endl;
	cin >> iNumber;
	return iNumber;

}

int calculateSum(int iFirstnumber,int iSecondNumber)
{
	int iResult;
	iResult = iFirstnumber + iSecondNumber;
	return iResult;
}

void showResult(int iResult)
{
	cout << "The sum is " << iResult << endl;
}

int main()
{
	int iFirstNumber, iSecondNumber, iResult;

	iFirstNumber = readData("the first number:");
	iSecondNumber = readData("the second number:");

	iResult = calculateSum(iFirstNumber, iSecondNumber);

	showResult(iResult);

	return 0;
}