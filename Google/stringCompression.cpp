#include <iostream>
#include <string>
using namespace std;

string decompress(int amount, string str)
{
    string decompressed = "";
    bool inNumber = false;

    int newAmount = 0;

    int startingNumberPos = 0;
    int startingStrPos = 0;
    int startingNonDecomPos = 0;

    for (int i = 0; i < str.length(); ++i)
    {
        if (inNumber)
        {
            if (str[i] == '[')
            {
                newAmount = stoi(str.substr(startingNumberPos, i - startingNumberPos));
                startingStrPos = i + 1;
            }

            if (str[i] == ']')
            {
                decompressed += decompress(newAmount, str.substr(startingStrPos, i - startingStrPos));
                inNumber = false;
                
                if (i != str.length() - 1)
                {
                    startingNonDecomPos = i;
                }
            }
        }
        if (str[i] <= '9')
        {
            if (!inNumber)
            {
                startingNumberPos = i;
                inNumber = true;
                decompressed = str.substr(startingNonDecomPos, i - startingNonDecomPos);
            }
        }
    }

    for (int i = 0; i < amount; ++i)
    {
        decompressed += str;
    }

    return decompressed;
}

int main()
{
    string compressed;

    cin >> compressed;

    cout << decompress(1, compressed);

    return 0;
}