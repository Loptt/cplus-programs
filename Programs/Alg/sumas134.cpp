#include <iostream>
using namespace std;

int d[1000];

int frog(int n)
{
    if (n == 1 || n == 2)
        return 1;
    
    d[1] = 1;
    d[2] = 1;
    d[3] = 2;

    for (int i = 4; i <= n; i++) 
    {
        d[i] = d[i-1] + d[i-3] + d[i-4]; 
    }

    return d[n];
}

int main()
{
    int n;
    cin >> n;
    cout << frog(n) << endl;
    return 0;
}