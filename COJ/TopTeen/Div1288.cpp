#include <iostream>
#include <string>
using namespace std;

int main()
{
	int tests;
	cin >> tests;

	for (int i = 0; i < tests; ++i)
	{
		bool isby2 = true, isby3 = true;

		int sum = 0;

		string arrnumber;

		cin >> arrnumber;

		for (int i = 0; i < arrnumber.size(); ++i)
		{
			sum += arrnumber[i] - 48;
		}

		if (arrnumber[arrnumber.size()-1]%2!=0)
		{
			isby2 = false;
		}

		if (sum%3!=0)
		{
			isby3 = false;
		}

		if (isby2 && isby3)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}

	}
}