#include <iostream>
using namespace std;

const bool bTesting = true;

int getNumber()
{
  if (bTesting)
  {
    cout << "Please enter the position for the series:" << endl;
  }
  int iNumber;
  cin >> iNumber;
  return iNumber;
}

int calculateSeries(int iPosition)
{
  int iCounter = 1;
  int iSeries = 1;
  
  while (iCounter < iPosition)
  {
    iSeries += 2;
    ++iCounter;
  }
  
  return iSeries;
}

void showResult(int iResult)
{
  if (bTesting)
  {
    cout << "The resulting element in the list is: ";
  }
  cout << iResult << endl;
}

int main()
{
  int iNumber, iResult;
  iNumber = getNumber();
  
  iResult = calculateSeries(iNumber);
  
  showResult(iResult);
  
  return 0;
}
