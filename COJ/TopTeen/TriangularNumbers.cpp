#include <iostream>
using namespace std;

int main()
{
	unsigned long long int number, sum = 0, counter = 1;
	bool istriangular = false;

	cin >> number;

	while (number != 0)
	{
		while (number != sum && sum < number)
		{
			sum += counter++;

			if (number == sum)
			{
				istriangular =true;
			}
		}

		cout << (istriangular ? "YES":"NO") << endl;

		sum = 0;
		counter = 1;
		istriangular = false;

		cin >> number;
	}
}