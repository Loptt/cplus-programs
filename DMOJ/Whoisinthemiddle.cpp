/*
NOT YET WORKING
*/

#include <iostream>
using namespace std;

int getData()
{
  int iWeight;
  cin >> iWeight;
  return iWeight;
}

int calculateMiddle(int iWeight1, int iWeight2, int iWeight3)
{
  if ((iWeight3 > iWeight1 && iWeight1 > iWeight2) ||
     (iWeight2 > iWeight1 && iWeight1 > iWeight3))
  {
    return iWeight1;
  }
  else
  {
    if ((iWeight3 > iWeight2 && iWeight2 > iWeight1) ||
       (iWeight1 > iWeight2 && iWeight2 > iWeight3))
    {
      return iWeight2;
    }
    else
    {
      if ((iWeight2 > iWeight3 && iWeight3 > iWeight1) ||
         (iWeight1 > iWeight3 && iWeight3 > iWeight2))
      {
        return iWeight3;
      }
    }
  }
}

void showData(int iResult)
{
  cout << iResult << endl;
}

int main()
{
  int iFirstWeight, iSecondWeight, iThirdWeight;
  int iMiddleWeight;
  
  iFirstWeight =  getData();
  iSecondWeight =  getData();
  iThirdWeight =  getData();
  
  iMiddleWeight = calculateMiddle(iFirstWeight, iSecondWeight,
                  iThirdWeight);
                  
  showData(iMiddleWeight);
  
  return 0;
}
