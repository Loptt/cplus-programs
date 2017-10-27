#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word;
	int size, upper = 0, lower = 0;
	cin >> size >> word;

	for (int i = 0; i < size; ++i)
	{
		if (word[i] < 97)
		{
			++upper;
		}
		else
		{
			++lower;
		}
	}

	cout << upper << " " << lower << endl;
	
	return 0;
}