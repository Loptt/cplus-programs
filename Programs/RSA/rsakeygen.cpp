#include <iostream>
#include <string>
using namespace std;

int max(int a, int b) 
{
    return a > b ? a : b;
}

unsigned int gcd (unsigned int a, unsigned int b) 
{
    unsigned int x;

    while (b) 
    {
        x = a % b;
        a = b;
        b = x;
    }

    return a;
}

int inverse(int a, int m) 
{
    for (int i = 0; i < m; i++) 
    {
        if ((i*a) % m == 1) 
        {
            return i;
        }  
    }

    cout << "ERROR: No inverse" << endl;
    exit(0);
    return 0;
}

bool isCoprime(int n, int m) 
{
    return gcd(n, m) <= 1;
}

int getCoprimeInRange(int a, int b, int n) 
{
    for (int i = a; a <= b; i++)
    {
        if (isCoprime(i, n))
        {
            return i;
        }
    }
    
    cout << "ERROR: No coprimes" << endl;
    exit(0);
    return 0;
}

void generate(int p, int q)
{
    int n = p * q;

    int d = getCoprimeInRange(max(p,q) + 1, n - 1, (p-1)*(q-1));

    int e = inverse(d, (p-1)*(q-1));

    cout << "Public: " << e << endl;
    cout << "Private: " << d << endl;
    cout << "N: " << n << endl;
}

int main()
{
    int p, q;
    cin >> p >> q;

    generate(p, q);
    return 0;
}