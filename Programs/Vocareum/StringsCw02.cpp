#include <string>
using namespace std;

/*
coutWords
Function to count the amount of words in a string
Parameters: A string to test
Return: the amount of words
*/
int countWords(string sText)
{
	int iLength = sText.length();
	int iWordCounter = 0;

	bool bIsNotInWord = true;

	for (int iCounter = 0; iCounter < iLength; ++iCounter)
	{
		if (bIsNotInWord)
		{
			if (sText[iCounter] != ' ')
			{
				bIsNotInWord = false;
				++iWordCounter;
			}
		}
		else
		{
			if (sText[iCounter] == ' ')
			{
				bIsNotInWord = true;
			}
		}

	}

	return iWordCounter;
}
