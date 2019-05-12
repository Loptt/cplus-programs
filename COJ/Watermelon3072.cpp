/*
Code created by Carlos Estrada
September 17, 2016
*/
#include <iostream>
#include <string>
using namespace std;

int getWeight()
{
	int iNumber;
	cin >> iNumber;
	return iNumber;
}

void showAnswer(string sMessage)
{
	cout << sMessage << endl;
}

void calculateDivision(int iWeight)
{
	int iModulus;
	iModulus = iWeight % 2;

	if (iModulus == 0 && iWeight != 2)
	{
		showAnswer("YES");
	}
	else
	{
		showAnswer("NO");
	}
}

int main()
{
	int iWeight = getWeight();

	calculateDivision(iWeight);

	return 0;
}