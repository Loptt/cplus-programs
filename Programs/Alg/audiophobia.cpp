#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

void floyd(int grafo[10][10], int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grafo[i][k] != INT_MAX && grafo[k][j] != INT_MAX)
                {
                    grafo[i][j] = min(grafo[i][j], max(grafo[i][k], grafo[k][j]));
                }
            }
        }
    }
}

int main() {
    int t, n, m, q;
    cin >> t;

    for (int i = 0; i < t; i++) {    
        
        cin >> n >> m >> q;

        int grafo[10][10];

        int a, b, c;

        for (int i = 0; i < n; i++)
        {
            grafo[i][i] = 0;
            for (int j = i + 1; j < n; j++)
            {
                grafo[i][j] = grafo[j][i] = INT_MAX;
            }
        }

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            grafo[a - 1][b - 1] = grafo[b - 1][a - 1] = c;
        }

        floyd(grafo, n);

        cout << "Case " << i+1 << ":" << endl;

        for (int i = 0; i < q; i++)
        {
            cin >> a >> b;
            if (grafo[a - 1][b - 1] == INT_MAX) {
                cout << "no path" << endl;
            } else {
                cout << grafo[a - 1][b - 1] << endl;
            }
        }
    }

    return 0;
}