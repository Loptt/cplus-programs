/*
CheckAge.cpp
Program to check the user's age
Created by Carlos
*/
#include <iostream>
using namespace std;

int getAge()
{
	int iAge;
	cout << "Please enter your age in years:" << endl;
	cin >> iAge;
	return iAge;
}

int checkAge(int iAge)
{
	int iAgeEvaluation;
	if (iAge < 13 && iAge >= 0)
	{
		iAgeEvaluation = 0;
	}
	else
	{
		if (iAge < 20 && iAge > 12)
		{
			iAgeEvaluation = 1;
		}
		else 
		{
			if (iAge >= 20)
			{
				iAgeEvaluation = 2;
			}
			else
			{
				iAgeEvaluation = 3;
			}
		}
	}
	return iAgeEvaluation;
}

void showResult(int iAgeEvaluation)
{
	if (iAgeEvaluation == 0)
	{
		cout << "You are a kid!" << endl;
	}
	else
	{
		if (iAgeEvaluation == 1)
		{
			cout << "You are a teen!" << endl;
		}
		else
		{
			if (iAgeEvaluation == 2)
			{
				cout << "You are an Adult" << endl;
			}
			else 
			{
				cout << "Your age is invalid" << endl;
			}
		}
	}
}


int main()
{
	int iAge, iAgeEvaluation;

	iAge = getAge();

	iAgeEvaluation = checkAge(iAge);

	showResult(iAgeEvaluation);

	return 0;
}