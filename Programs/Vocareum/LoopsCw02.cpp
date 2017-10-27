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
calculateFactorial
function to calculate the factorial
Parameters: the number inputted
return: the result of the operation
*/
int calculateFactorial(int iNumber)
{
  int iResult = 1;
  int iCounter = 1;

  while (iCounter <= iNumber)
  {
    iResult *= iCounter;
    ++iCounter;
  }

  return iResult;
}

/*
showResult
function to output the result
Parameters: The result of the operation
return: none
*/
void showResult(int iResult)
{
  cout << iResult << endl;
}

/*
main
function to call all other functions
Parameters: none
return: 0
*/
int main()
{
  int iNumber, iResult;

  //Get the input
  iNumber = getNumber();

  //Process the data
  iResult = calculateFactorial(iNumber);

  //Output the result
  showResult(iResult);

  return 0;
}
