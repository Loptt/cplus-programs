#include <iostream>
using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;

	int cake[y][x];

	int candle1x, candle1y, candle2x, candle2y;
	int slicebeginx, slicebeginy, sliceendx, sliceendy;
	cin >> candle1x >> candle1y >> candle2x >> candle2y;

	if (candle1x == candle2x)
	{
		slicebeginy = candle1y;
		sliceendy = candle2y;
		slicebeginx = 0;
		sliceendx = x;
	}
	else
	{
		if (candle1y == candle2y)
		{
			slicebeginy = 0;
			sliceendy = y;
			slicebeginx = candle1x;
			sliceendx = candle2x;
		}
		else
		{
			slicebeginx = 0;
			sliceendx = x;
			slicebeginy = candle1y;
			sliceendy = candle2y;
		}
	}

	cout << slicebeginx << " " << slicebeginy << " " << sliceendx << " ";
	cout << sliceendy << endl;
}