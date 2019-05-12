#include <iostream>
#include <string>

using namespace std;

int findFinalLength(const string &s)
{
    int ones = 0, zeroes = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            ones++;
        else
            zeroes++;
    }

    return ones - zeroes >= 0 ? ones - zeroes : zeroes - ones;
}

int main(int argc, char const *argv[])
{
    int n;
    string s;
    
    cin >> n;
    cin >> s;

    cout << findFinalLength(s) << endl;
    return 0;
}