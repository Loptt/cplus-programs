/*
Code created by Carlos Estrada
September 18, 2017
*/

#include <iostream>
#include <cstdio>
using namespace std;

int getData()
{
	int iNumber;
	scanf("%d", &iNumber);
	return iNumber;
}

void printNumber(int iNumber)
{
	printf("%d\n", iNumber );
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
