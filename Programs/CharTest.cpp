#include <iostream>
using namespace std;

int main()
{
	char cWord[];

	cin >> cWord;

	int iSize = sizeof(cWord);

	for (int i = 0; i <= iSize ; --iSize)
	{
		cout << cWord[iSize];
	}

	cout << endl;
}