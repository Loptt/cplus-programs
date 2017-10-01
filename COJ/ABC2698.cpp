/*
NOT WORKING
NEEDS RESTRUCTURIZATION	
*/
#include <iostream>
#include <string>
using namespace std;

char getString()
{
	char sString;
	cin >> sString;
	return sString;
}

int assignValue(char sString[], int iCount)
{
	int iLetterValue = 0;
	switch(sString[iCount])
	{
		case 'A':
			iLetterValue = 1;
			break;
		case 'B':
			iLetterValue = 2;
			break;
		case 'C':
			iLetterValue = 3;
			break;
		case 'D':
			iLetterValue = 4;
			break;
		case 'E':
			iLetterValue = 5;
			break;
		case 'F':
			iLetterValue = 6;
			break;
		case 'G':
			iLetterValue = 7;
			break;
		case 'H':
			iLetterValue = 8;
			break;
		case 'I':
			iLetterValue = 9;
			break;
		case 'J':
			iLetterValue = 10;
			break;
		case 'K':
			iLetterValue = 11;
			break;
		case 'L':
			iLetterValue = 12;
			break;
		case 'M':
			iLetterValue = 13;
			break;
		case 'N':
			iLetterValue = 14;
			break;
		case 'O':
			iLetterValue = 15;
			break;
		case 'P':
			iLetterValue = 16;
			break;
		case 'Q':
			iLetterValue = 17;
			break;
		case 'R':
			iLetterValue = 18;
			break;
		case 'S':
			iLetterValue = 19;
			break;
		case 'T':
			iLetterValue = 20;
			break;
		case 'U':
			iLetterValue = 21;
			break;
		case 'V':
			iLetterValue = 22;
			break;
		case 'W':
			iLetterValue = 23;
			break;
		case 'X':
			iLetterValue = 24;
			break;
		case 'Y':
			iLetterValue = 25;
			break;
		case 'Z':
			iLetterValue = 26;
			break;
		default:
			iLetterValue = 0;
			break;
		}

	return iLetterValue;
}

int calculateSum(char cCharacters[27])
{
	int iSum = 0;

	for (int i = 0; i < 27; ++i)
	{
		int iLetterValue = assignValue(cCharacters[27], i);
		iSum += iLetterValue;
	}

	return iSum;
}

void showResult(iSum)
{
	cout << iSum << endl;
}

int main()
{
	char sString = getString();

	int iSum = calculateSum(sString);

	showResult(iSum);

	return 0;
}