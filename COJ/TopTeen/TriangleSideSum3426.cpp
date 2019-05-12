#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	long long int a, b, inicio, final, sum = 0;
	scanf("%lld %lld", &a, &b);

	if (a>=b)		
	{
		inicio = a-b;
	}
	else
	{
		inicio = b-a;
	}

	final = a + b - 1;

	sum = (final*(final+1))/2 - (inicio*(inicio+1))/2; 

	printf("%lld\n", sum);

	return 0;
}