#include <iostream>
using namespace std;

int main()
{
	int piezas[8];
	int sumas[8];
	int maxNum = 0;

	for (int i = 0; i < 8; ++i)
	{
		cin >> piezas[i];
	}

	for (int i = 0; i < 5; ++i)
	{
		sumas[i] = piezas[i] + piezas[i+1] + piezas[i+2] + piezas[i+3];
	}

	sumas[5] = piezas[5] + piezas[6] + piezas[7] + piezas[0];
	sumas[6] = piezas[6] + piezas[7] + piezas[0] + piezas[1];
	sumas[7] = piezas[7] + piezas[0] + piezas[1] + piezas[2];

	for (int i = 0; i < 8; ++i)
	{
		if (sumas[i] > maxNum)
		{
			maxNum = sumas[i];
		}
	}

	cout << maxNum << endl;
	return 0;
}