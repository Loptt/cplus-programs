#include <iostream>
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int sumTriangle(int D[10][10], int n)
{
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            D[i][j] += max(D[i+1][j], D[i+1][j+1]);
        }
    }

    return D[0][0];
}

int main()
{
    int D[10][10];
    int tests;
    cin >> tests;

    while (tests--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cin >> D[i][j];
            }
        }

        cout << sumTriangle(D, n) << endl;
    }
    return 0;
}