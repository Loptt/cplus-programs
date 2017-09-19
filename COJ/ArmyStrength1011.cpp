#include <iostream>
#include <cstdio>
using namespace std;

int getData()
{
	int iNumber;
	scanf("%d", &iNumber);
	return iNumber;
}

void showWinner(bool bGozillaisWinner)
{
	char cGodzilla[] = "Godzilla";
	char cMechaGodzilla[] = "MechaGodzilla";

	if (bGozillaisWinner)
	{
		printf("%s\n", cGodzilla);
	}
	else
	{
		printf("%s\n", cMechaGodzilla);
	}
}

void calculateWinner(int GZSize, int MGSize)
{
	int GZArmy[GZSize];
	int MGArmy[MGSize];

	for (int iCounter = 0; iCounter < GZSize; ++iCounter)
	{
		cin >> GZArmy[iCounter];
	}
	for (int iCounter = 0; iCounter < MGSize; ++iCounter)
	{
		cin >> MGArmy[iCounter];
	}

	if (MGSize > GZSize)
	{
		
	}
}

void testCases(int iTestCases, int iMGMonsters, int iGZMonsters)
{
	for (int iCounter = 0; iCounter < iTestCases; ++iCounter)
	{
		calculateWinner();
	}
	return ;
}

int main()
{
	int iTestCases;
	int iMGMonsters, iGZMonsters;

	iTestCases = getData();
	iMGMonsters = getData();
	iGZMonsters = getData();

	testCases(iTestCases, iMGMonsters, iGZMonsters);

	return 0;

}