#include <iostream>
#include <string>
using namespace std;

int main()
{
	char string1[] = " ";
	char string2[] = " ";
	bool isSub = true;

	int elcontador = 0;

	cin >> string1;
	cin >> string2;

	for (int i = 0; i < sizeof(string1); ++i)
	{
		int counter = i;

		for (int i = 0; i < sizeof(string2); ++i)
		{
			while(string1[counter] != string2[i] && elcontador <= sizeof(string2))
			{
				++elcontador;
			}
			if (elcontador >= sizeof(string2))
			{
				isSub = false;
			}
		}
	}

	if (isSub)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	return 0;
}