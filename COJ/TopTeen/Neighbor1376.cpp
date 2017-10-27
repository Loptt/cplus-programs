#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string number, number2;
	cin >> number;
	char storage;
	int i = number.length()-2;
	int position = 0;

	while (number[i+1]<=number[i] && i> -1)
	{
		--i;
	}
	cout << i << endl;
	if (i > -1)
	{
		int smallest = 100;

		for (int j = i + 1 ; j < number.length(); ++j)
		{
			if (number[j] < smallest && number[j] > number[i])
			{
				smallest = number[j];
				position = j;
			}
		}

		storage = number[i];
		number[i] = number[position];
		number[position] = storage;

		sort(number.begin()+i+1, number.end());

		cout << number << endl;
	}
	else
	{
		cout << 0 << endl;
	}
	return 0;
}