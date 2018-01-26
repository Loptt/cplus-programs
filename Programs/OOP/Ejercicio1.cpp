#include <fstream>
#include <string>
using namespace std;

int main() 
{
    ifstream inputFile;
    ofstream outputFile;

    inputFile.open("tiempos.txt");
    outputFile.open("promedios.txt");

    string sMatricula;
    int iAmount;
    double dTime, dSum = 0; 

    while (inputFile >> sMatricula >> iAmount)
    {
        for (int iCounter = 0; iCounter < iAmount; ++iCounter)
        {
            inputFile >> dTime;
            dSum += dTime;
        }

        outputFile << sMatricula << ' ' << dSum / iAmount << endl;

        dSum = 0;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}