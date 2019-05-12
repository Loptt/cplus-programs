#include <iostream>
#include <string>
using namespace std;

int main()
{
	string number;
	int wordnumber;

	getline(cin, number);

	while (number[0] != '-')
	{
		cin >> wordnumber;
		string wordlist[wordnumber];

		string numberofword[wordnumber]; 

		for (int i = 0; i < wordnumber; ++i)
		{
			getline(cin, wordlist[i]);

			for (int j = 0; j < wordlist[i].length(); ++j)
			{
				switch (wordlist[i][j])
				{
					case 'i':
					case 'j':
						numberofword[i] += '1';
						break;

					case 'a':
					case 'b':
					case 'c':
						numberofword[i] += '2';
						break;

					case 'd':
					case 'e':
					case 'f':
						numberofword[i] += '3';
						break;

					case 'g':
					case 'h':
						numberofword[i] += '4';
						break;

					case 'k':
					case 'l':
						numberofword[i] += '5';
						break;

					case 'm':
					case 'n':
						numberofword[i] += '6';
						break;

					case 'p':
					case 'r':
					case 's':
						numberofword[i] += '7';
						break;

					case 't':
					case 'u':
					case 'v':
						numberofword[i] += '8';
						break;

					case 'w':
					case 'x':
					case 'y':
						numberofword[i] += '9';
						break;

					case 'o':
					case 'q':
					case 'z':
						numberofword[i] += '0';
						break;
				} 
			}
		}

		s

		getline(cin, number);		
	}

	return 0;
}	