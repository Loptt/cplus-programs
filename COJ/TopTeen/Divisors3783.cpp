#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int tests;
	scanf("%d", &tests);

	while(tests--)
	{
		int number, multipleof, sum = 0;
		vector<int> divisors;

		scanf("%d %d", &number, &multipleof);

		//cout << "checkpoint" << endl;
		for (int i = 1; i <= sqrt(number); ++i)
		{
			//cout << "checkpoint" << endl;
			if (number % i == 0)
			{
				//cout << "checkpoint" << endl;
				divisors.push_back(i);
				divisors.push_back(number/i);
			}
		}

		//cout << "checkpoint" << endl;

		for (int i = 0; i < divisors.size(); ++i)
		{
			if (divisors[i] % multipleof != 0)
			{
				sum += divisors[i];
			}
		}
		if (number == 1)
		{
			printf("%d\n", 1);
		}
		else
		{
			printf("%d\n", sum);
		}
	}

	return 0;
}