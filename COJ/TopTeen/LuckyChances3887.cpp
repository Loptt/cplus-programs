#include <iostream>
using namespace std;
const bool test = false;
int main()
{
	int x, y, cantidad = 0;
	bool posibilidadganar = true;
	cin >> y >> x;

	int grid[y][x];

	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			for (int arriba = i-1; arriba >= 0 ; --arriba)
			{
				if (grid[i][j] <= grid[arriba][j])
				{
					posibilidadganar = false;
				}
			}

			if (i != 0)
			{
				if (posibilidadganar)
				{
					++cantidad;
					if (test)
					{
						cout << grid[i][j] << " arriba" << endl;
					}
				}
			}

			posibilidadganar = true;

			for (int abajo = i+1; abajo < y; ++abajo)
			{
				if (grid[i][j] <= grid[abajo][j])
				{
					posibilidadganar = false;
				}
			}

			if (i != y -1)
			{
				if (posibilidadganar)
				{
					++cantidad;
					if (test)
					{
						cout << grid[i][j] << " abajo" << endl;
					}
				}
			}

			posibilidadganar = true;

			for (int izquierda = j-1; izquierda >= 0; --izquierda)
			{
				if (grid[i][j] <= grid[i][izquierda])
				{
					posibilidadganar = false;
				}
			}

			if (j != 0)
			{
				if (posibilidadganar)
				{
					++cantidad;
					if (test)
					{
						cout << grid[i][j] << " izquierda" << endl;
					}
				}
			}

			posibilidadganar = true;

			for (int derecha = j+1; derecha < x; ++derecha)
			{
				if (grid[i][j] <= grid[i][derecha])
				{
					posibilidadganar = false;
				}
			}

			if (j != x-1)
			{
				if (posibilidadganar)
				{
					++cantidad;
					if (test)
					{
						cout << grid[i][j] << " derecha" << endl;
					}
				}
			}


			posibilidadganar = true;
		}
	}

	cout << cantidad + (2*x) + (2*y) << endl;

	return 0;
}