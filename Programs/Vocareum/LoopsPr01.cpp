int simpleSeries(int iPosition)
{
  int iSum = 1, iCounter = 1;

  while (iCounter < iPosition)
  {
    iSum += 2;
    ++iCounter;
  }

  return iSum;
}
