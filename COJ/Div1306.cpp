#include <iostream>
#include <string>
using namespace std;

int main()
{
	string number;
	cin >> number;

	int penultimo = number[number.length()-2] -48;
	int ultimo = number[number.length()-1] -48;

	int lasttwo = penultimo*10+ultimo;

	cout << (lasttwo%4==0?"YES":"NO") << endl;
}