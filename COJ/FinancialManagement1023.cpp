#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	double balance, average, round, sum = 0;

	for (int i = 0; i < 12; ++i)
	{
		cin >> balance;
		sum += balance;
	}

	average = sum / 12;

	cout <<'$'<< average << endl;


	return 0;
}