#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int amountdonors, amountqueries, queries, donors, sum = 0;
	scanf("%d", &amountdonors);

	int cumulativedonation[amountdonors];

	for (int i = 0; i < amountdonors; ++i)
	{
		scanf("%d", &donors);
		sum += donors;
		cumulativedonation[i] = sum;
	}

	scanf("%d", &amountqueries);

	for (int i = 0; i < amountqueries; ++i)
	{
		scanf("%d", &queries);
		if (queries > sum)
		{
			printf("%s\n", "none");
		}
		else
		{
			for (int j = 0; j < amountdonors; ++j)
			{
				if (cumulativedonation[j] >= queries)
				{
					printf("%d\n", j+1);
					break;
				}
			}
		}
	}
}