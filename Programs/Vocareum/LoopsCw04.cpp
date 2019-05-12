/*
Carlos Estrada A01039919
LoopsCw04
October 10, 2017
*/

/*
fibo
Function to calculate the sum of a series given the position
Parameters: The position entered by the user
Return: the resulting sum
*/
int fibo(int iPosition)
{
    int iSum = 1;
    int iPrevSum = 1;
    int iPrevPrevSum = 1;

    for (int i = 2; i < iPosition; ++i)
    {
         iSum = iPrevSum + iPrevPrevSum;
         iPrevPrevSum = iPrevSum;
         iPrevSum = iSum;
    }

    return iSum;
}
