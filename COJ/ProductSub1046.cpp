#include <iostream>
using namespace std;

int main()
{
	int tests;
	cin >> tests;

	while(tests--)
	{
		int a, b; 
		long int sum = 0;
		cin >> a >> b;
		int count = b-a;

		for (int i = a; i <= b; ++i)
		{
			sum += i*(i+1)*(i+2);
		}

		cout << sum % 100 << endl;
	}

	return 0;
}