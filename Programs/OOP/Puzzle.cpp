#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

void configureBoard(int iMatPuzzle[4][4])
{
    vector<int> configs;

    for (int iCounter = 0; iCounter < 16; ++iCounter)
    {
        configs.push_back(iCounter);
    }

    srand(time(NULL));

    random_shuffle(configs.begin(), configs.end());

    int iVectorCounter = 0;

    for (int iRowIndex = 0; iRowIndex < 4; ++iRowIndex)
    {
        for (int iColIndex = 0; iColIndex < 4; ++iColIndex) 
        {
            iMatPuzzle[iRowIndex][iColIndex] = configs[iVectorCounter];
            ++iVectorCounter;
        }
    }

}

int getUserInput()
{
    int iNumber;
    cout << endl << ">>> ";
    cin >> iNumber;
    return iNumber;
}

bool changePosition(int iMatPuzzle[4][4], int iRowIndex, int iColIndex)
{   
    bool bIsValidInput = false;

    if (iMatPuzzle[iRowIndex+1][iColIndex] == 0)
    {
        if (iRowIndex+1 > 3)
        {
            return bIsValidInput;
        }

        iMatPuzzle[iRowIndex+1][iColIndex] = iMatPuzzle[iRowIndex][iColIndex];
        iMatPuzzle[iRowIndex][iColIndex] = 0;
        bIsValidInput = true;
        return bIsValidInput;
    }
    else
    {
        if (iMatPuzzle[iRowIndex-1][iColIndex] == 0)
        {
            if (iRowIndex-1 < 0)
            {
                return bIsValidInput;
            }

            iMatPuzzle[iRowIndex-1][iColIndex] = iMatPuzzle[iRowIndex][iColIndex];
            iMatPuzzle[iRowIndex][iColIndex] = 0;
            bIsValidInput = true;
            return bIsValidInput;
        }
        else
        {
            if (iMatPuzzle[iRowIndex][iColIndex-1] == 0)
            {
                if (iColIndex-1 < 0)
                {
                    return bIsValidInput;
                }

                iMatPuzzle[iRowIndex][iColIndex-1] = iMatPuzzle[iRowIndex][iColIndex];
                iMatPuzzle[iRowIndex][iColIndex] = 0;
                return bIsValidInput;
            }
            else
            {
                if (iMatPuzzle[iRowIndex][iColIndex+1] == 0)
                {
                    if (iColIndex+1 > 3)
                    {
                        return bIsValidInput;
                    }

                    iMatPuzzle[iRowIndex][iColIndex+1] = iMatPuzzle[iRowIndex][iColIndex];
                    iMatPuzzle[iRowIndex][iColIndex] = 0;
                    bIsValidInput = true;
                    return bIsValidInput;
                }
            }
        }
    }
}

void processTurn(int iMatPuzzle[4][4], bool &bIsRunning)
{
    int iInput;
    int bIsValidInput = false;
    iInput = getUserInput();

    if (iInput)
    {
        for (int iRowIndex = 0; iRowIndex < 4; ++iRowIndex)
        {
            for (int iColIndex = 0; iColIndex < 4; ++iColIndex)
            {
                if (iMatPuzzle[iRowIndex][iColIndex] == iInput)
                {
                    bIsValidInput = changePosition(iMatPuzzle, iRowIndex, iColIndex);

                    if (bIsValidInput)
                    {
                        break;
                    }
                }
            }

            if (bIsValidInput)
            {
                break;
            }
        }
    }
    else
    {
        bIsRunning = false;
    }   
}

bool isWinner(int iMatPuzzle[4][4], bool &bIsRunning)
{
    int iCounting = 1;

    for (int iRowIndex = 0; iRowIndex < 4; ++iRowIndex)
    {
        for (int iColIndex = 0; iColIndex < 4; ++iColIndex) 
        {
            if (iMatPuzzle[iRowIndex][iColIndex] != iCounting)
            {
                return false;
            }

            if (iCounting == 15)
            {
                iCounting = 0;
            }
            else
            {
                ++iCounting; 
            }
        }
    }

    bIsRunning = false;
    return true;
}

void displayPuzzle(int iMatPuzzle[4][4])
{
    for (int iCounter = 0; iCounter < 50; ++iCounter)
    {
        cout << endl;
    }
    
    cout << "       _____________" << endl;

    for (int iRowIndex = 0; iRowIndex < 4; ++iRowIndex)
    {
        cout << "      |";
        for (int iColIndex = 0; iColIndex < 4; ++iColIndex)
        {
            cout << setw(3);
            if (iMatPuzzle[iRowIndex][iColIndex] != 0)
            {
                cout << iMatPuzzle[iRowIndex][iColIndex];
            }
            else
            {
                cout << ' ';
            }
        }

        cout << " |" << endl;
    }

    cout << "      |_____________|" << endl;
}

int main()
{
    int iMatPuzzle[4][4];

    configureBoard(iMatPuzzle);

    bool bIsRunning = true;
    bool bIsWinner = false;

    while (bIsRunning)
    {
        displayPuzzle(iMatPuzzle);
        processTurn(iMatPuzzle, bIsRunning);
        bIsWinner = isWinner(iMatPuzzle, bIsRunning);
    }

    if (bIsWinner)
    {
        cout << endl << "YOU WON" << endl;
    }
    else
    {
        cout << endl << "Game Quit" << endl;
    }

    return 0;
}