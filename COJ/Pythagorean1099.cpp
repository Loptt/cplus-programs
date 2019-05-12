#include <iostream> 
using namespace std;

int main()
{
	int number1, number2, number3, biggest = 0, small1, small2;

	while(true)
	{
		cin >> number1;

		if (!number1)
		{
			break;
		}
		
		cin >> number2 >> number3;

		if (number1 > number2 && number1 > number3)
		{
			biggest = number1;
			small1 = number2;
			small2 = number3;
		}
		else
		{
			if (number2 > number1 && number2 > number3)
			{
				biggest = number2;
				small1 = number1;
				small2 = number3;
			}
			else
			{
				biggest = number3;
				small1 = number2;
				small2 = number1;
			}
		}

		cout << (biggest*biggest==small1*small1+small2*small2?"right":"wrong");
		cout << endl;
	}

	return 0;
}