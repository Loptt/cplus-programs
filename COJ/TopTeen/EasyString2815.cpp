#include <iostream>
#include <string>
using namespace std;

int main()
{
	int tests;
	int position = 0;
	int counter = 0;

	
	string str1, str2, newstr1;

	cin >> tests;

	for (int i = 0; i < tests; ++i)
	{
		cin >> str1 >> str2;

		position = str1.find(str2);

		while(position >= 0)
		{
			str1.erase(position, str2.length());
			position = str1.find(str2);
			++counter;
		}

		cout << counter << endl;

		counter = 0;
	}
	return 0;
}