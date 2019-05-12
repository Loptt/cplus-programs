#include <iostream>
using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}

int camino(int D[1000][1000], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j > 0)
            {
                D[i][j] += D[i][j - 1];
            }

            if (j == 0 && i > 0)
            {
                D[i][j] += D[i - 1][j];
            }

            D[i][j] += min(D[i - 1][j], D[i][j - 1]);
        }
    }

    return D[n - 1][n - 1];
}

int main()
{
    int D[1000][1000];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> D[i][j];
        }
    }

    cout << camino(D, n) << endl;

    return 0;
}