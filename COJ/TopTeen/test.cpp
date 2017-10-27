#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int amountdonors;
	scanf("%d", &amountdonors);

	int donors[amountdonors];

	int sum = 0;
	int cumulativedonation[amountdonors];

	for (int i = 0; i < amountdonors; ++i)
	{
		scanf("%d", &donors[i]);
		sum += donors[i];
		cumulativedonation[i] = sum;
	}

	int amountqueries;
	scanf("%d", &amountqueries);
	int queries[amountqueries];

	for (int i = 0; i < amountqueries; ++i)
	{
		scanf("%d", &queries[i]);
		for (int j = 0; j < amountdonors; ++j)
		{
			if (queries[i] > sum)
			{
				printf("%s\n", "none");
				break;
			}
			if (cumulativedonation[j] >= queries[i])
			{
				printf("%d\n", j+1);
				break;
			}
		}
	}

	return 0;
}