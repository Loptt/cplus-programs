#include <iostream>
#include <string>
using namespace std;

int main()
{
    string number;
    cin >> number;

    int sum = 0;

    while (number != "0")
    {
        for (int i = 0; i < number.length(); ++i)
        {
            if (i % 2 == 0)
            {
                sum += number[i] - 48;
            }
            else
            {
                sum += (number[i] - 48) * -1;
            }
        }

        cout << number;
        cout << (sum%11==0?" is a multiple of 11.":" is not a multiple of 11.") << endl;
        
        sum = 0;
        cin >> number;
    }

    return 0;
}