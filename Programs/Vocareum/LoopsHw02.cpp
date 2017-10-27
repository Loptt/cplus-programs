/*
Carlos Estrada A01039919
October 13, 2017
Programming Fundamentals
*/

#include <iostream>
using namespace std;

/*
getNumber
Function to get the input from the user
Parameters: none
Return: the number inputted
*/
int getNumber()
{
    int iNumber;
    cin >> iNumber;
    return iNumber;
}

/*
calculateSum
Funtion to caluclate the sum of alternating sign fractions.
Parameters: the number inputted by the user
Return: the sum
*/
double calculateSum(int iPosition)
{
    double dNumerator = 1;
    double dDenominator = 2;
    double dSum = 0.5;

    for (int iCounter = 2; iCounter <= iPosition; ++iCounter)
     {
    	++dNumerator;
    	++dDenominator;

    	if (iCounter % 2 == 0)
    	{
    		dSum += (dNumerator / dDenominator)* (-1);
    	}
    	else
    	{
    		dSum += (dNumerator / dDenominator);
    	}
    }

    return dSum;
}

/*
showResult
Function to output the result
Parameters: none
Return: 0
*/
void showResult(double dResult)
{
	cout << dResult << endl;
}

/*
main
Funtion to call other function
Parameters: none
Return: 0
*/
int main()
{
    //Declare variable and get input from user
    int iNumber;
    double dResult;

    iNumber = getNumber();

    dResult = calculateSum(iNumber);
    

    showResult(dResult);
    
    return 0;    
}