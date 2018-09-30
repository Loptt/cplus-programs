#include <iostream>
#include <vector>
using namespace std;

const int N_SIZE = 4;
const int M_SIZE = 4;

struct Zero
{
    int x, y;

    Zero(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

void fillMatrix(int matrix[M_SIZE][N_SIZE])
{
    for (int i = 0; i < M_SIZE; ++i)
    {
        for (int j = 0; j < N_SIZE; ++j)
        {
            cin >> matrix[i][j];
        }
    }
}

void applyZeroes(int matrix[M_SIZE][N_SIZE], Zero zero)
{
    for (int i = 0; i < M_SIZE; ++i)
    {
        matrix[i][zero.x] = 0;
    }

    for (int i = 0; i < N_SIZE; ++i)
    {
        matrix[zero.y][i] = 0;
    }
}

void doZeroMatrix(int matrix[M_SIZE][N_SIZE])
{
    vector<Zero> zeroes;

    for (int i = 0; i < M_SIZE; ++i)
    {
        for (int j = 0; j < N_SIZE; ++j)
        {
            if (!matrix[i][j])
            {
                Zero temp(j,i);
                zeroes.push_back(temp);
            }
        }
    }

    for (int i = 0; i < zeroes.size(); ++i)
    {
        applyZeroes(matrix, zeroes[i]);
    }
}

void printMatrix(int matrix[M_SIZE][N_SIZE])
{
    cout << endl;
    
    for (int i = 0; i < M_SIZE; ++i)
    {
        for (int j = 0; j < N_SIZE; ++j)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

int main()
{
    int matrix[M_SIZE][N_SIZE];

    fillMatrix(matrix);

    doZeroMatrix(matrix);

    printMatrix(matrix);

    return 0;
}