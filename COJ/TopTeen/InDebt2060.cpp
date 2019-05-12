#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	while (n != -1)
	{
		int sum = 0;
		int askmoney = 0;
		int prices;

		for (int i = 0; i < n; ++i)
		{
			cin >> prices;
			sum += prices;

			if (sum % 100 == 0)
			{
				++askmoney; 
			}
		}

		cout << askmoney << endl;

		cin >> n;

		askmoney = 0;
	}
	return 0;
}