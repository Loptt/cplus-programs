/*
Not Working
*/

#include <iostream> 
#include <cstdio>
using namespace std;

int getNumber()
{
	int iNumber;
	scanf("%d", &iNumber);
	return iNumber;
}

void calculateSum(int iTests)
{
	int iA, iB, iCount;
	int iSum, iMult = 0;

	for (int i = 0; i < iTests; ++i)
	{
		iA = getNumber();
		iB = getNumber();

		iCount = iB - iA;
		iSum = 0;

		for (iA; iA <= iB; ++iA)
		{
			iMult = iA * (iA + 1) * (iA + 2);
			iSum += iMult;
		}

		printf("%d\n", iSum);
	}
}

int main()
{
	int iTests = getNumber();

	calculateSum(iTests);

	return 0;
}