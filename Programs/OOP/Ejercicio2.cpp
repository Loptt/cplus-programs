#include <fstream>
#include <iostream>
using namespace std;

int getPlaces(string sFrase)
{
    int iPlaces = 0;

    for (int iCounter = 0; iCounter < sFrase.length(); ++iCounter)
    {
        if (sFrase[iCounter] == ' ')
        {
            ++iPlaces;
        }
    }

    return iPlaces;
}

void addSpaces(string &sFrase, int iSpacePerPlace, int &iExtraSpaces, int iExtCount)
{
    for (int iCounter = 0; iCounter < iSpacePerPlace; ++iCounter)
    {
        sFrase.insert(iExtCount, " ");
    }

    if (iExtraSpaces)
    {
        sFrase.insert(iExtCount, " ");
        --iExtraSpaces;
    }
}

int main()
{
    ifstream inputFile;
    ofstream outputFile;

    inputFile.open("textoOriginal.txt");
    outputFile.open("justificado.txt");

    int iSpacesAdd, iSpacePerPlace, iPlaces, iExtraSpaces;
    string sFrase;

    while(getline(inputFile, sFrase))
    {   
        if (sFrase.length() < 25)
        {
            iSpacesAdd = 25 - sFrase.length();
            iPlaces = getPlaces(sFrase);
            iSpacePerPlace = iSpacesAdd / iPlaces; 


            iExtraSpaces = iSpacesAdd % iPlaces;

            for (int iCounter = sFrase.length()-1; iCounter >= 0; --iCounter)
            {
                if (sFrase[iCounter] == ' ')
                {
                    addSpaces(sFrase, iSpacePerPlace, iExtraSpaces, iCounter);
                }

            }

            outputFile << sFrase << endl; 
        }
        else
        {
            outputFile << sFrase << endl;
        }
        
    }

    inputFile.close();
    outputFile.close();

    return 0;
}