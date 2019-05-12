#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	double n;
	vector<double> v;

	while(cin >> n)
	{	
		v.push_back(n);
	}

	for (int i = v.size()-1; i >= 0; --i)
	{
		cout << sqrt(v[i]) << endl;
	}

	return 0;
}