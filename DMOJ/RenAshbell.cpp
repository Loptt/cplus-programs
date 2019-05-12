#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() 
{
    int people, ren, other;
    bool isStronger = true;
    cin >> people >> ren;

    for (int i = 0; i < people-1; ++i)
    {
        cin >> other;

        if (other > ren)
        {
            isStronger = false;
        }
        
    }

    cout << (isStronger?"YES":"NO") << endl;
}