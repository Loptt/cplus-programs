#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void trim(string &sText)
{
    string result;

    for (int j = 0; j < sText.length(); j++)
    {
        if (sText[j] != ' ')
            result += sText[j];
    }

    sText = result;
}

string encrypt(string sText, string key)
{
    double k = sText.size();
    double n = key.size();
    int dimY = ceil(k / n);
    vector<string> mat(dimY, "");
    string result = "";
    int iCounter = 0;

    for (int i = 0; i < dimY; i++)
    {
        for (int j = 0; j < n && iCounter < k; j++, iCounter++)
        {
            mat[i] += sText[iCounter];
            cout << sText[iCounter] << " ";
        }
        cout << endl;
    }

    iCounter = 0;

    for (int j = 0; j < n && iCounter < k; j++, iCounter++)
    {
        for (int i = 0; i < dimY; i++)
        {
            /*if (mat[i][j] < 'A' || mat[i][j] > 'Z') {
                continue;
            }*/
            result += mat[i][j];
        }
    }
    return result;
}

string decrypt(string sText, string key)
{
    double k = sText.size();
    double n = key.size();
    int dimY = ceil(k / n);
    vector<string> mat(n, "");
    string result = "";
    int iCounter = 0;
    cout << "TEXT  " <<  sText << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < dimY && iCounter < k; j++, iCounter++)
        {
            mat[i] += sText[iCounter];
            cout << sText[iCounter] << " ";
        }

        cout << endl;
    }

    cout << endl;

    iCounter = 0;

    for (int j = 0; j < dimY && iCounter < k; j++, iCounter++)
    {
        for (int i = 0; i < n; i++)
            result += mat[i][j];
    }

    return result;
}

int main()
{
    string sTextDecrypted;
    string sTextEncrypted;
    string key = "SIDI";
    sTextDecrypted = "MFEOAOWUYRITCTHEHEBY";

    trim(sTextDecrypted);
    sTextEncrypted = encrypt(sTextDecrypted, key);
    trim(sTextEncrypted);
    cout << sTextEncrypted << endl;
    cout << decrypt(sTextEncrypted, key) << endl;

    return 0;
}

