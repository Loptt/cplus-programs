#include <iostream>
#include <string>
using namespace std;

int main()
{
    int tests;
    cin >> tests;

    while (tests--)
    {
        string number;
        cin >> number;

        int penultimo = number[number.length()-2] - 48;
        int ultimo = number[number.length()-1] - 48;

        int numberInt = penultimo * 10 + ultimo;

        if (numberInt % 4 == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}