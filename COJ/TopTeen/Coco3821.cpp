#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int athletes, position;
	scanf("%d", &athletes);
	char space = ' ';

	int sumscores[athletes];

	for (int i = 0; i < athletes; ++i)
	{
		int listscores[10];
		int sum = 0;

		for (int j = 0; j < 10; ++j)
		{
			scanf("%d", &listscores[j]);
		}

		sort(listscores, listscores+10);

		for (int j = 1; j < 9; ++j)
		{
			sum += listscores[j];
		}

		sumscores[i] = sum;
	}

	for (int i = 0; i < athletes; ++i)
	{
		position = i+1;
		printf("%d %c %d\n", position, space, sumscores[i]);
	}

	sort(sumscores, sumscores+athletes);
	printf("%d\n", sumscores[athletes-1]);
	//cout << sumscores[athletes-1] << endl;

	return 0;
}