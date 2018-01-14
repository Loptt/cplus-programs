#include <iostream>
#include <string>
using namespace std;

int main()
{
	string list;
	getline(cin, list);

	for (int i = 0; i < list.length(); ++i)
	{
		if (list[i] != '	')
		{
			cout << list[i] << ',';
		}
	}

	cout << endl;

	return 0;
}