#include <iostream>
#include <string>
using namespace std;

bool addNumber(string &compressed, int &amountComp, int counter)
{
    string number = to_string(counter);

    for (int i = 0; i < number.length(); ++i)
    {
        if (amountComp + i >= compressed.length())
            return false;

        compressed[amountComp + i] = number[i];
    }

    amountComp += number.length();

    return true;
}

string compress(string s)
{
    string compressed = s;

    char currentChar = s[0];
    int counter = 1;
    int amountComp = 0;

    for (int i = 1; i < s.length(); ++i)
    {
        if (s[i] == currentChar)
        {
            ++counter;
        }
        else
        {
            compressed[amountComp++] = currentChar;

            if (!addNumber(compressed, amountComp, counter))
                return s;

            counter = 1;
            currentChar = s[i];
        }
    }

    compressed[amountComp++] = currentChar;

    if (!addNumber(compressed, amountComp, counter))
        return s;

    if (amountComp == s.length())
        return s;

    return compressed.substr(0, amountComp);
}

int main()
{
    string str;

    cin >> str;

    cout << compress(str) << endl;
    return 0;
}