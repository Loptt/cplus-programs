#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int tests;
	scanf("%d", &tests);

	int x1, x2, y1, y2, xsum, ysum, distance;

	for (int i = 0; i < tests; ++i)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		if (x1>x2)
		{
			xsum = x1 - x2;
		}
		else
		{
			xsum = x2 - x1;
		}

		if (y1>y2)
		{
			ysum = y1 - y2;
		}
		else
		{
			ysum = y2 - y1;
		}

		distance = ysum + xsum;

		printf("%d\n", distance);
	}
	return 0;
}