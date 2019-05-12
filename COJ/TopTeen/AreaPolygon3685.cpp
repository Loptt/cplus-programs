#include <iostream>
using namespace std;

int main()
{
	int tests, x;
	cin >> tests;

	while (tests--)
	{
		cin >> x;

		cout << x*x*2+x*x+2 << endl;
	}
}