#include <iostream>
#include <cstdio>
using namespace std;

void round(double x)
{
   double y = 100 * x;
   int rounded = (int)(y + 0.5);
   printf("%d.%02d\n", rounded / 100, rounded % 100);
}

int main()
{
	float fList[12];
	float fSum = 0;
	float fAverage = 0;

	for (int i = 0; i < 12; ++i)
	{
		scanf("%f", &fList[i]);
	}

	for (int i = 0; i < 12; ++i)
	{
		fSum += fList[i];
	}

	fAverage = fSum / 12;

	char sign = '$';

	printf("%c", sign);
	round(fAverage);
	printf("\n");

	return 0;
}