#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int tests, ng, nm;
	cin >> tests;

	while(tests--)
	{
		cin >> ng >> nm;

		int fg, mfg = 0, fmg, mfmg = 0;

		for (int i = 0; i < ng; ++i)
		{
			cin >> fg;

			if (fg > mfg)
			{
				mfg = fg;
			}
		}

		for (int i = 0; i < nm; ++i)
		{
			cin >> fmg;

			if (fmg > mfmg)
			{
				mfmg = fmg;
			}
		}

		if (mfmg > mfg)
		{
			cout << "MechaGodzilla" << endl;
		}
		else
		{
			cout << "Godzilla" << endl;
		}
	}
}