#include <iostream>
#include <string>
#include <vector>
using namespace std;

int expand(int b, int n, vector<int> &expansion) 
{
    expansion.clear();

    int q = n;
    int k = 0;

    int res = 0;
    while (q)
    {
        res = q % b;
        q = q / b;
        expansion.push_back(res);
        k++;
    }

    return k; 
}

char decrypt(int c, int e, int n)
{
    vector<int> expansion;

    int k = expand(2, e, expansion);

    int x = 1;
    int power = c % n;

    for (int i = 0; i < k; i++)
    {
        if (expansion[i] == 1)
        {
            x = (x * power) % n;
        }

        power = (power * power) % n;
    }

    return (char) x;   
}

int main()
{
    int e, n;
    cin >> e >> n;

    int l = 0;
    int val = 0;

    while (cin >> val)
    {
        cout << decrypt(val, e, n);
    }
    cout << endl;

    return 0;
}