#include <iostream>
using namespace std;

int getNumber()
{
  int iNumber;
  cin >> iNumber;
  return iNumber;
}

int calculateFactorial(int iNumber)
{
  int iResult = 1;
  int iCounter = 1 ;
  
  while (iCounter <= iNumber)
  {
    iResult *= iCounter;
    ++iCounter;
  }
  
  return iResult;
}

void showResult(int iResult)
{
  cout << iResult << endl;
}

int main()
{
  int iNumber, iResult;
  iNumber = getNumber();
  
  iResult = calculateFactorial(iNumber);
  
  showResult(iResult);
  
  return 0;
}