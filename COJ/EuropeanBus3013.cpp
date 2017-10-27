#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int tests, x, y;
	cin >> tests;

	for (int i = 0; i < tests; ++i)
	{
		cin >> x;
		y = pow(2,x) - 1;
		
		cout << y << endl;
	}
	
	return 0;
}