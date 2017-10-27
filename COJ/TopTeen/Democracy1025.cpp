#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int groups, minamount = 0, wingroups;
	cin >> groups;

	int voters[groups];

	for (int i = 0; i < groups; ++i)
	{
		cin >> voters[i];
	}

	sort(voters, voters+groups);

	for (int i = 0; i < groups/2+1; ++i)
	{
		minamount += voters[i]/2+1;
	}

	cout << minamount << endl;

	return 0;
}