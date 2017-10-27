#include <iostream>
using namespace std;


/*
getNumber
Function to get the input from the user
Parameters: None
Return: the number entered
*/
int getNumber()
{
  int iNumber;
  cin >> iNumber;
  return iNumber;
}

/*
calculateSeries
Function to process the input and calculate the resulting position in the series
Parameters: the number inputted by the user
Return: the resulting number of the series
*/
int calculateSeries(int iElement)
{
  int iCount = 0;

  if (((iElement + 2) % 4) == 0 && iElement < 0)
  {
    do
    {
      iElement += 4;
      ++iCount;
    }
    while (iElement != 2);

    return iCount;
  }
  else
  {
    return iCount - 1;
  }

}

/*
showResult
Function to output the result
Parameters: The result of the process
Return: nothing
*/
void showResult(int iResult)
{
  cout << iResult << endl;
}

/*
main
Function to call other function
Parameters: none
Return: 0
*/
int main()
{
  //Declare variables
  int iNumber, iResult;
  
  //Ask the user for the value
  iNumber = getNumber();
  
  //Process the data inputted
  iResult = calculateSeries(iNumber);
  
  //Output the result
  showResult(iResult);
  
  return 0;
}