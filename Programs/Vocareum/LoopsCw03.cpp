/*
Carlos Estrada A01039919
LoopsCw03
October 10, 2017
*/

#include <iostream>
using namespace std;

/*
getNumber
function to get the input from the user
Parameters: None
return: the input
*/
int getNumber()
{
  int iNumber;
  cin >> iNumber;
  return iNumber;
}

/*
calculateSum
function to calculate the factorial
Parameters: the number inputted
return: the result of the operation
*/
float calculateSum(int iPosition)
{
  float fSum = 0;
  float fFraction = 2;

  for (int i = 0; i < iPosition; ++i)
  {
  	fSum += ( 1 / fFraction );
  	++fFraction;
  }

  return fSum;
}

/*
showResult
function to output the result
Parameters: The result of the operation
return: none
*/
void showResult(float fResult)
{
  cout << fResult << endl;
}

/*
main
function to call all other functions
Parameters: none
return: 0
*/
int main()
{
  int iNumber;
  float fResult;

  //Get the input
  iNumber = getNumber();

  //Process the data
  fResult = calculateSum(iNumber);

  //Output the result
  showResult(fResult);

  return 0;
}
