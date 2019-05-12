#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool checkIfEditAway(string s1, string s2)
{
    if (abs((int)(s1.length() - s2.length())) > 1)
        return false;

    bool diffFound = false;

    if (abs((int)(s1.length() - s2.length())) == 1)
    {
        bool s1IsLonger = s1.length() > s2.length();
        int length = s1IsLonger ? s2.length() : s1.length();

        for (int i = 0, j = 0; i < length && j < length; ++i, ++j)
        {
            if (s1[i] != s2[j])
            {
                if (diffFound)
                    return false;

                diffFound = true;

                if (s1IsLonger)
                {
                    ++i;
                }
                else
                {
                    ++j;
                }
            }
        }

        return true;
    }

    for (int i = 0; i < s1.length(); ++i)
    {
        if (s1[i] != s2[i])
        {
            if (diffFound)
                return false;
            else
                diffFound = true;
        }
    }

    return true;
}

int main()
{
    string s1, s2;

    cin >> s1 >> s2;

    cout << (checkIfEditAway(s1,s2) ? "YES" : "NO") << endl;
}