/*
Code created by Carlos Estrada
Classwork Switch
September 18, 2017
*/

#include <iostream>
using namespace std;

/*
readMonth
Function to get the number of the month from the user
Parameters: none
Return: the month number (int)
*/
int readMonth()
{
  int iMonth;
  cin >> iMonth;
  return iMonth;
}

/*
calculateNumberOfDays
Function to get the number of days given the month number
Parameters: the month number (int)
Return: the number of days (int)
*/
int calculateNumberOfDays(int iMonth)
{
  int iDays = 0;
  
  switch(iMonth)
  {
    case 1:
      iDays = 31;
      break;
      
    case 2:
      iDays = 28;
      break;
      
    case 3:
      iDays = 31;
      break;
    case 4:
      iDays = 30;
      break;
      
    case 5:
      iDays = 31;
      break;
      
    case 6:
      iDays = 30;
      break;
      
    case 7:
      iDays = 31;
      break;
      
    case 8:
      iDays = 31;
      break;
      
    case 9:
      iDays = 30;
      break;
    
    case 10:
      iDays = 31;
      break;
    
    case 11:
      iDays = 30;
      break;
      
    case 12:
      iDays = 31;
      break;
      
    default:
      cout << "Invalid month" << endl;
  }
  
  return iDays;
}

/*
showResult
Displays the number of days
Parameters: the number of days (int)
Return: nothing
*/
void showResult(int iResult)
{
  cout << iResult << endl;
}

/*
main
Function to call all other functions
Parameters: none
Return: 0 
*/
int main()
{
  //Declare the variables
  int iMonth, iDays;
  
  //Read the number of month from the user
  iMonth = readMonth();
  
  //Call a function to calculate the number of days in the given month
  iDays = calculateNumberOfDays(iMonth);
  
  //Display the result to the console
  showResult(iDays);
  
  return 0;
  
}