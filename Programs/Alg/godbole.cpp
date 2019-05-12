#include <iostream>
#include <cstring>
#include <iomanip>
#include <climits>
using namespace std;

struct Res
{
    int min;
    int k;
};

void printMatrix(int grafo[10][10], int n, int it)
{
    cout << "Iteracion " << it << ":" << endl;

    cout << setw(7) << " |  ";
    for (int i = 1; i <= n; i++)
    {
        if (i == 0)
        {
            cout << setw(3) << i;
        }
        else
        {
            cout << setw(5) << i;
        }
    }

    cout << endl
         << "_________________________________________" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << setw(2) << i << "  |";
        for (int j = 1; j <= n; j++)
        {
            if (grafo[i][j] ==  INT_MAX) {
                cout << setw(5) << "MAX";
            }
            else {
                cout << setw(5) << grafo[i][j];
            }
        }
        cout << endl;
    }
}

Res min(int i, int j, int D[10][10], int d[10])
{
    Res res;
    res.min = INT_MAX;

    for (int k = i; k < j; k++) {
        if (D[i][k] + D[k+1][j] + d[i-1]*d[k]*d[j] < res.min)
        {
            res.min = D[i][k] + D[k+1][j] + d[i-1]*d[k]*d[j];
            res.k = k;
        }
    }

    return res;
}

int godbole(int D[10][10], int d[10], int n, int P[10][10])
{
    for (int i=1; i <= n; i++)
    {
        D[i][i] = 0;
    }

    printMatrix(D, n, 0);

    for (int diag = 1; diag <= n-1; diag++)
    {
        for (int i = 1; i <= n - diag; i++)
        {
            int j = i + diag;
            Res res = min(i, j, D, d);
            D[i][j] = res.min;
            P[i][j] = res.k;
        }

        printMatrix(D, n, diag);
    }

    return D[1][n];
}

int main()
{
    int D[10][10];
    int d[10];
    int n;
    int P[10][10];
    
    cin >> n;

    for (int i = 0; i < n+1; i++)
    {
        cin >> d[i];
    }

    memset(D, 0, sizeof(D));
    memset(P, 0, sizeof(P));

    cout << godbole(D, d, n, P) << endl;

    printMatrix(P, n, 1);

    return 0;
}