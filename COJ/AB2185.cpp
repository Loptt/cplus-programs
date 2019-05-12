#include <iostream>
using namespace std;

int getData()
{
  int iNumber;
  cin >> iNumber;
  return iNumber;  
}

int calculateSum(int iNumber1, int iNumber2)
{
  int iResult;
  iResult = iNumber1 + iNumber2;
  return iResult;
}

int calculateSub(int iNumber1, int iNumber2)
{
  int iResult;
  iResult = iNumber1 - iNumber2;
  return iResult;
}

int calculateMult(int iNumber1, int iNumber2)
{
  int iResult;
  iResult = iNumber1 * iNumber2;
  return iResult;
}


int calculateDiv(int iNumber1, int iNumber2)
{
  int iResult;
  iResult = iNumber1 / iNumber2;
  return iResult;
}

int calculateMod(int iNumber1, int iNumber2)
{
  int iResult;
  iResult = iNumber1 % iNumber2;
  return iResult;
}

void showData(int iResult)
{
  cout << iResult << endl;
}

int main()
{
  int iFirstNumber, iSecondNumber, iResult;
  int iSum, iSub, iMult, iDiv, iMod;
  
  iFirstNumber = getData();
  iSecondNumber = getData();
  
  iSum = calculateSum(iFirstNumber, iSecondNumber);
  iSub = calculateSub(iFirstNumber, iSecondNumber);
  iMult = calculateMult(iFirstNumber, iSecondNumber);
  iDiv = calculateDiv(iFirstNumber, iSecondNumber);
  iMod = calculateMod(iFirstNumber, iSecondNumber);
  
  showData(iSum);
  showData(iSub);
  showData(iMult);
  showData(iDiv);
  showData(iMod);

  return 0;  
}
