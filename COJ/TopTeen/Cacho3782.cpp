#include <iostream>
using namespace std;

int main()
{
	int tests;
	cin >> tests;

	int dado[5];

	bool isescala = true;

	while (tests--)
	{
		for (int i = 0; i < 5; ++i)
		{
			cin >> dado[i];
		}

		for (int i = 1; i < 5; ++i)
		{
			if (dado[i]-1 != dado[i-1])
			{
				isescala = false;
			}
		}

		cout << (isescala ? 'Y':'N') << endl;

		isescala = true;
	}
}