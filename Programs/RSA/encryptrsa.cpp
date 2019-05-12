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

int encrypt(char c, int d, int n)
{
    vector<int> expansion;

    int k = expand(2, d, expansion);
/*
    for (int i = 0; i < k; i++)
    {
        cout << expansion[i] << " ";
    }

    cout << endl;
    */
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

    return x;   
}

int main()
{
    int d, n;
    cin >> d >> n;

    string message;
    cin.ignore();
    cin.ignore();

    getline(cin, message);

    for (int i = 0; i < message.length(); i++)
    {
        cout << encrypt(message[i], d, n) << " ";
    }

    cout << endl;

    return 0;
}