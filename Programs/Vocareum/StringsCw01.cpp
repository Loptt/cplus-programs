#include <iostream>
#include <string>
using namespace std;

bool palindrome(string sWord)
{
	bool bIsPalindrome = true;

	int iLength = sWord.length();

	for (int iCounter = 0; iCounter < iLength; ++iCounter)
	{
		if (sWord[iCounter] != sWord[iLength-1-iCounter] && sWord[iCounter] + 32 != sWord[iLength-1-iCounter] &&
		    sWord[iCounter] != sWord[iLength-1-iCounter] + 32)
		{
			bIsPalindrome = false;
		}
	}

	return bIsPalindrome;
}

int main()
{
	string s;
	cin >> s;
	bool bIsPalindrome = palindrome(s);

	cout << bIsPalindrome << endl;
}