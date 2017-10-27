#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word;
	cin >> word;

	int iposition = 0;

	iposition = word.find("i");

	if (iposition < 0)
	{
		cout << "S" << endl;
	}
	else
	{
		cout << "N" << endl;
	}
	return 0;
}