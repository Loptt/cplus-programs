#include <iostream>
#include <string>

using namespace std;

char findUnique(const string &s, int min, int max)
{
    if (min == max)
        return s[min];
    
    int mid = ((max - min) / 2) + min;
    bool odd = (max - min) % 4 == 0;

    if ((s[mid - 1] != s[mid]) && (s[mid + 1] != s[mid]))
        return s[mid];
    
    if (odd)
    {
        if (s[mid] == s[mid + 1])
            return findUnique(s, mid + 2, max);
        else
            return findUnique(s, min, mid - 2);
    }
    else
    {
        if (s[mid] == s[mid + 1])
            return findUnique(s, min, mid - 1);
        else
            return findUnique(s, mid + 1, max);
    }
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;

    cout << findUnique(s, 0, s.length() - 1) << endl;    
    return 0;
}