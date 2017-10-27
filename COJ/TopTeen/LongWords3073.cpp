#include <iostream>
#include <string>
using namespace std;

int main()
{
	int tests;
	string word;
	cin >> tests;

	while (tests--)
	{
		cin >> word;

		if (word.length()>10)
		{
			cout << word[0] << word.length()-2 << word[word.length()-1] << endl;
		}
		else
		{
			cout << word << endl;
		}
	}
	return 0;
}