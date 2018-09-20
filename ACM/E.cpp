#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    int n = 0;
    int count = 0;

    bool isValid = true;

    cin >> s1 >> s2;

    for (int i = 0; i < s1.length() - s2.length() + 1; i++)
    {
        for (int k = i, j = 0; j < s2.length(); j++, k++)
        {
            count = j;
            if (s1[k] == s2[j])
            {
                isValid = false;
                break;
            }
        }

        if (isValid)
        {
            n++;
        }

        isValid = true;
    }

    cout << n << endl;

    return 0;
}

//FDMLCRDMRALF