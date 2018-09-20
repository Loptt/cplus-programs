#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int N, num, victorias = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num;

        if (num != 1)
        {
            victorias++;
        }
    }

    cout << victorias << endl;

    return 0;
}