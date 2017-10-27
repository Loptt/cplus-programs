#include <iostream>
#include <string>
using namespace std;

int main()
{
	int tests, dotposition, newdotposition, squaresize = 1, oldsquare = 0, counter = 0;
	bool hassquare = false;
	cin >> tests;

	while (tests--)
	{
		int n;
		cin >> n;

		string grid[n];
		string dotlist[10] = {".", "..", "...", "....", ".....", "......",
						    ".......", "........", ".........",  ".........."};

		for (int i = 0; i < n; ++i)
		{
			cin >> grid[n];
		}

		cout << grid[1] << endl;
/*
		for (int dots = n-1; dots >= 0 && !hassquare ; ++dots)
		{
			hassquare = true;

			for (int line = 0; line <= n - dots && !hassquare; ++line)
			{
				dotposition = grid[line].find(dotlist[dots]);

				if (dotposition >= 0)
				{
					for (int checkline = line + 1; checkline < line + dots; ++checkline)
					{
						newdotposition = grid[checkline].find(dotlist[dots]);

						if (dotposition != newdotposition)
						{
							hassquare = false;
						}
					}
				}
			}

			if (hassquare)
			{
				squaresize = dots + 1;
			}
		}

		cout << squaresize << endl;


		/*

		for (int dots = 0; dots < n; ++dots)
		{
			for (int line = 0; line < n; ++line)
			{
				freeposition = grid[line].find(dotlist[dots]);

				if (freeposition >= 0)
				{
					for (int a = 0; a < dots && a+line < n; ++a)
					{
						if (freeposition != grid[line+a].find(dotlist[dots]))
						{
							hassquare = false;
						}

						++counter;
					}

					if (counter < dots+1)
					{
						hassquare = false;
					}

					if (hassquare)
					{
						squaresize = dots+1;
					}		
				}


			}
		}

		cout << squaresize << endl;

		/*
		char grid[n][n];

		for (int line = 0; line < n; ++line)
		{
			for (int i = 0; i < n; ++i)
			{
				cin >> grid[i][line];
			}
		}

		for (int line = 0; line < n; ++line)
		{
			for (int i = 0; i < n; ++i)
			{
				if (grid[i][line] == '.')
				{
					cout << "heyou" << endl;
				}
			}
		}

*/		
	}
	return 0;
}