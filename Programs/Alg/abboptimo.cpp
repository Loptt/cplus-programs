#include <iostream>
#include <climits>
using namespace std;

int sumatoria(int i, int j, int p[10])
{

}

int minimo(int i, int j, int A[10][10])
{
    int min = INT_MAX
}

void optimize(int A[10][10], int R[10][10], int p[10], int n)
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
    int A[10][10];
    int R[10][10];
    int p[10];
    return 0;
}