#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word;
	cin >> word;

	if (word.length()%2==0)
	{
		for (int i = (word.length()/2-1); i >= 0; --i)
		{
			cout << word[i];
		}	

		for (int i = (word.length()-1); i >= word.length()/2; --i)
		{
			cout << word[i];
		}

		cout << endl;
	}
	else
	{
		for (int i = (word.length()/2 - 1 ); i >= 0; --i)
		{
			cout << word[i];
		}	

		cout << word[word.length()/2];

		for (int i = (word.length()-1); i > word.length()/2; --i)
		{
			cout << word[i];
		}

		cout << endl;
	}

	return 0;
}