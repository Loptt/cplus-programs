#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string sInput;
	cin >> sInput;

	char numbers[sInput.length()];

	for (int i = 0; i < sInput.length(); ++i)
	{
		if (i % 2 == 0)
		{
			numbers[i/2] = sInput[i];
		}
	}

	sort(numbers.begin(), numbers.end());

	for (int i = 0; i < sInput.length()/2; ++i)
	{
		cout << numbers[i];
	}

	cout << endl;

	return 0;

}