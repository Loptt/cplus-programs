#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name = "Carlos Estrada";
	string firstname = name.substr(0,6);
	string lastname = name.substr(7);

	cout << firstname << " " << lastname << endl;
	string concatenation = firstname + " " + lastname;

	cout << concatenation << endl;

	return 0;
}