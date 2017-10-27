#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int n1, m1;
	scanf("%d %d", &n1, &m1);


	int movements;
	scanf("%d", &movements);

	while(movements--)
	{
		char direction;
		int amount;
		scanf("%c %d", &direction, &amount);

		switch (direction)
		{
			case 'E':
				m1 -= amount;
				break;

			case 'W':
				m1 += amount;
				break;

			case 'S':
				n1 -= amount;
				break;
			
			case 'N':
				n1 += amount;
				break;
		}
	}

	char d =' ';

	printf("%d %c %d\n", n1, m1, d);

	cout << n1 << " " << m1 << endl;

	return 0;
}
/*
int getInt()
{
	int iNum;
	cin >> iNum;
	return iNum;
}

char getCoordinate()
{
	char cOption;
	cin >> cOption;
	return cOption;
}

void showAns(int iPosx, int iPosy)
{
	cout << iPosx << " " << iPosy << endl;
}

void getInicial(int iPosfinalx, int iPosfinaly, int iRepeat)
{
	int iPosinicialX, iPosinicialY, iAmountmov;
	char cOption;
	for (int i = 0; i < iRepeat; i++)
	{
		cOption = getCoordinate();
		iAmountmov = getInt();
		switch(cOption)
		{
			case'E': iPosfinalx = iPosfinalx - iAmountmov;
				break;
			case'W': iPosfinalx = iPosfinalx + iAmountmov;
				break;
			case'N': iPosfinaly = iPosfinaly + iAmountmov;
				break;
			case'S': iPosfinaly = iPosfinaly - iAmountmov;
				break;
		}
	}
	//show result after loop is over
	showAns(iPosfinalx, iPosfinaly);

}

int main ()
{
	//Declaring and Evaluating Variables
	int iGridsizex = getInt();
	int iGridsizeY = getInt();
	int iPosfinalx = getInt();
	int iPosfinaly = getInt();
	int iRepeat = getInt();

	getInicial(iPosfinalx,iPosfinaly,iRepeat);


	return 0;
}
*/