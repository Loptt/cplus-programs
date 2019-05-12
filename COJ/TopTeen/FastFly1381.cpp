#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int tests;
	cin >> tests;

	float dm, db1, db2, D, v1, v2, vm, t, mosquita;
	mosquita = 0.0;
	dm = 1.0;

	for (int i = 0; i < tests; ++i)
	{
		cin >> D >> v1 >> v2 >> vm;

		t = D / (v1 + v2);
		dm = t * vm;

		cout << fixed << setprecision(2) << dm << endl;
	}
}