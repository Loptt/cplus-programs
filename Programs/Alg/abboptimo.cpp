#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

void printMatrix(double grafo[10][10], int n, int it)
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

            cout << setw(5) << grafo[i][j];
        }
        cout << endl;
    }
}

double sumatoria(int i, int j, double p[10])
{
    double sum = 0;

    for (int k = i; k <= j; k++)
    {
        sum += p[k];
    }

    return sum;
}

double minimo(int i, int j, double A[10][10])
{
    double min = INT_MAX;

    for (int k = i; k <= j; k++)
    {
        if (A[i][k-1] + A[k+1][j] < min)
        {
            min = A[i][k-1] + A[k+1][j];
        }
    }

    return min;
}

double optimize(double A[10][10], int R[10][10], double p[10], int n)
{
    for (int i = 1; i <= n; i++) // inicialización de matrices de resultados
    {
        A[i][i - 1] = 0;
        A[i][i] = p[i];
        R[i][i] = i;
        R[i][i - 1] = 0;
    }

    A[n + 1][n] = 0;
    R[n + 1][n] = 0;

    for (int diag = 1; diag <= n - 1; diag++)
    {
        for (int i = 1; i <= n - diag; i++)
        {
            int j = i + diag;
            A[i][j] = minimo(i, j, A) + sumatoria(i, j, p);
        }
        /*La función mínimo calcula el valor mínimo entre los diversos valores de: 
	A[i,k-1] + A[k+1, j]  para k desde i hasta j . La función sumatoria calcula la suma de las probabilidades de la llave I hasta la llave j .*/
    }
    return A[1][n];
}

int main()
{
    double A[10][10];
    int R[10][10];
    double p[10];

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    cout << optimize(A, R, p, n) << endl;

    printMatrix(A, n, 0);

    return 0;
}