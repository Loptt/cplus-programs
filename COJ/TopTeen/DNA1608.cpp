#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string word;
	vector<string> lista;

	while(word)
	{
		lista.push_back(word);
		cin >> word;		
	}

	return 0;
}