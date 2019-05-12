#include <iostream>
using namespace std;

int main()
{
	int n, k, amount = 0, winner = 0, winamount = 0;
	bool iswinner = true;
	cin >> n >> k;

	int primes[] = {2, 3, 5, 7, 11, 13,
				   17, 19, 23, 29, 31, 37,
				   41, 43, 47, 53, 59, 61,
				   67, 71, 73, 79, 83, 89,
				   97};

	int array[n][k];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			cin >> array[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			for (int a = 0; a < 25; ++a)
			{
				if (array[i][j] == primes[a])
				{
					++amount; 
				}
			}
		}

		if (amount > winamount)
		{
			winner = i + 1;
			winamount = amount;
			iswinner = true;
		}
		else
		{
			if (amount == winamount)
			{
				iswinner = false;
			}
		}

		//cout << amount << endl;

		amount = 0;
	}

	if (iswinner)
	{
		if (winamount == 1)
		{
			cout << "Object " << winner << " wins with " << winamount;
			cout << " rare characteristic" << endl;
		}
		else
		{
			cout << "Object " << winner << " wins with " << winamount;
			cout << " rare characteristics" << endl;
		}
	}
	else
	{
		cout << "No winner" << endl;
	}
}