#include <iostream>
using namespace std;

int main()
{
	int tests, floor;
	int prevfloor = 1;
	int sectotal = 0;
	cin >> tests;

	for (int i = 0; i < tests; ++i)
	{
		cin >> floor;

		if (floor >= prevfloor)
		{
			sectotal += floor - prevfloor;
			prevfloor = floor;
		}
		else
		{
			sectotal += prevfloor - floor;
			prevfloor = floor;
		}
	}

	sectotal += floor - 1;

	cout << sectotal << endl;
	
	return 0;
}