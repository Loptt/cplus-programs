#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

string getString()
{
	string sWord;
	cin >> sWord;
	return sWord;
}

int getNumber()
{
	int iNumber;
	cin >> iNumber;
	return iNumber;
}

string reverseString(string sString)
{
	string sReversed = sString;
	reverse(sReversed.begin(), sReversed.end());
	return sReversed;
}

bool hasOnlyMirrorLetters(string sString)
{
	int iPosition = sString.find_first_of("B");

	if (iPosition >= 0)
	{
		return false;
	}

	iPosition = sString.find_first_of("C");

	if (iPosition >= 0)
	{
		return false;
	}

	iPosition = sString.find_first_of("D");

	if (iPosition >= 0)
	{
		return false;
	}

	iPosition = sString.find_first_of("E");

	if (iPosition >= 0)
	{
		return false;
	}

	iPosition = sString.find_first_of("F");

	if (iPosition >= 0)
	{
		return false;
	}

	iPosition = sString.find_first_of("G");

	if (iPosition >= 0)
	{
		return false;
	}

	iPosition = sString.find_first_of("J");

	if (iPosition >= 0)
	{
		return false;
	}

	iPosition = sString.find_first_of("K");

	if (iPosition >= 0)
	{
		return false;
	}

	iPosition = sString.find_first_of("L");

	if (iPosition >= 0)
	{
		return false;
	}

	iPosition = sString.find_first_of("N");

	if (iPosition >= 0)
	{
		return false;
	}

	iPosition = sString.find_first_of("P");

	if (iPosition >= 0)
	{
		return false;
	}

	iPosition = sString.find_first_of("Q");

	if (iPosition >= 0)
	{
		return false;
	}

	iPosition = sString.find_first_of("R");

	if (iPosition >= 0)
	{
		return false;
	}

	iPosition = sString.find_first_of("S");

	if (iPosition >= 0)
	{
		return false;
	}

	iPosition = sString.find_first_of("Z");

	if (iPosition >= 0)
	{
		return false;
	}

	return true;
}

bool isPalindrome(string sNormal)
{
	string sReversed = reverseString(sNormal);

	if (sNormal != sReversed)
	{
		return false;
	}

	return true;
}

void showResult(bool bIsPalindrome, bool bIsMirror)
{
	if (bIsPalindrome && bIsMirror)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}

int main()
{
	int iTests = getNumber();

	for (int i = 0; i < iTests; ++i)
	{
		string sString = getString();
		bool bIsPalindrome = isPalindrome(sString);
		bool bIsOnlyMirror = hasOnlyMirrorLetters(sString);

		showResult(bIsPalindrome, bIsOnlyMirror);
	}

	return 0;
}