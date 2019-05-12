#include <iostream>
using namespace std;

int getNumber()
{
	cout << "introduce un numero" << endl;
	int iNumber;
	cin >> iNumber;
	return iNumber;
}

void showResult(int iNumber)
{
	int iSum = 0;
	int iSumador = 1;

	for (int i = 0; i < iNumber; i = i + 2)
	{
		if (iSumador > 0)
		{
			if (iSumador == 1)
			{
				iSum += iSumador;
				cout << iSumador;	
			}
			else
			{
				cout << '+' << iSumador;
				iSum += iSumador;
			}

			iSumador += 2;
			iSumador = iSumador * (-1);
		}
		else
		{
			cout << iSumador;
			iSum += iSumador;
			iSumador = iSumador * (-1);
			iSumador += 2;
		}
	}


	cout << '=' << iSum << endl;
}

int main()
{
	int iNumber = getNumber();

	showResult(iNumber);

	return 0;
}