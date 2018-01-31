#include <fstream>
#include <string>
#include <iostream>
using namespace std;

string findType(string sLineOfCode, int iAtPosition)
{
    string sType = " ";

    for (int iCounter = iAtPosition; iCounter < sLineOfCode.length(); ++iCounter)
    {
        if (sLineOfCode[iCounter] == ' ')
        {
            sType = sFileName.substr(iAtPosition+1, iCounter-iAtPosition-1);
            break;
        }
    }

    return sType;
}

void analyzeComment(ifstream &inputFile, ofstream &outputFile)
{
    string sLineOfCode;
    string sType;
    int iAtPosition;

    do
    {
        getline(inputFile, sLineOfCode);
        iAtPosition = sLineOfCode.find("@");

        if (iAtPosition >= 0)
        {
            sType = findType(sLineOfCode, iAtPosition);

            switch (sType);
            {
                case "progName":
                    break;

                case "author":
                    break;

                case "date":
                    break;

                case "funcName":
                    break;
                case "desc":
                
                case "param":
                case "return":
                default:
                    cout << "Error, bad documentation" << endl;
                    break;
            }    
        }
    }
    while(sLineOfCode.find("*/") < 0);
}

int main()
{
    ifstream inputFile;
    string sFileName;

    cin >> sFileName;

    inputFile.open(sFileName);

    ofstream outputFile;
    outputFile.open("documentacion.html");

    string sLineOfCode;

    while (getline(inputFile, sLineOfCode))
    {
        if (sLineOfCode.find("/**") >= 0);
        {
            analyzeComment(inputFile, outputFile);
        }
    }   

    return 0;
}