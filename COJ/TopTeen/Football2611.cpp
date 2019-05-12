#include <iostream>
using namespace std;

int main()
{
	int matches, power, totalpoints;

	cin >> matches >> power;

	int arrgoals[matches*2];

	for (int i = 0; i < matches*2; ++i)
	{
		cin >> arrgoals[i];
	}

	for (int i = 0; i < matches*2; ++i)
	{
		if (arrgoals[i] > arrgoals[i+1])
		{
			totalpoints += 3;
		}
	}

}