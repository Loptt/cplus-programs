#include <cstdio>
using namespace std;

int main()
{
    int size, sum;
    int amount = 0;
    scanf("%d", &size);

    for (int i = 1; i <= size; ++i)
    {
        sum = (i*i + i)/2;

        if (!(sum % 3))
        {
            ++amount;
        }        
    }

    printf("%d \n", amount);

    return 0;
}