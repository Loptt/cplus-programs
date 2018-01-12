#include <iostream>
#include <iomanip>
using namespace std;

int getUserInput()
{
    int iNumber;
    cout << ">>> ";
    cin >> iNumber;
    return iNumber;
}

void processTurn(int iMatPuzzle[4][4])
{
    int iInput;
    int bIsValidInput = false;
    iInput = getUserInput();

    for (int iRowIndex = 0; iRowIndex < 4; ++iRowIndex)
    {
        for (int iColIndex = 0; iColIndex < 4; ++iColIndex)
        {
            if (iMatPuzzle[iRowIndex][iColIndex] == iInput)
            {
                if (iMatPuzzle[iRowIndex+1][iColIndex] == 1234)
                {
                    iMatPuzzle[iRowIndex+1][iColIndex] = iMatPuzzle[iRowIndex][iColIndex];
                    iMatPuzzle[iRowIndex][iColIndex] = 1234;
                    bIsValidInput = true;
                    cout << "abajo" << endl;
                    break;
                }
                else
                {
                    if (iMatPuzzle[iRowIndex-1][iColIndex] == 1234)
                    {
                        iMatPuzzle[iRowIndex-1][iColIndex] = iMatPuzzle[iRowIndex][iColIndex];
                        iMatPuzzle[iRowIndex][iColIndex] = 1234;
                        bIsValidInput = true;
                        cout << "arriba" << endl;
                        break;
                    }
                    else
                    {
                        if (iMatPuzzle[iRowIndex][iColIndex-1] == 1234)
                        {
                            iMatPuzzle[iRowIndex][iColIndex-1] = iMatPuzzle[iRowIndex][iColIndex];
                            iMatPuzzle[iRowIndex][iColIndex] = 1234;
                            cout << "izquierda" << endl;
                            bIsValidInput = true;
                            break;
                        }
                        else
                        {
                            if (iMatPuzzle[iRowIndex][iColIndex+1] == 1234)
                            {
                                iMatPuzzle[iRowIndex][iColIndex+1] = iMatPuzzle[iRowIndex][iColIndex];
                                iMatPuzzle[iRowIndex][iColIndex] = 1234;
                                bIsValidInput = true;
                                cout << "derecha" << endl;
                                break;
                            }
                        }
                    }
                }
            }
        }

        if (bIsValidInput)
        {
            break;
        }
    }
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
            if (iMatPuzzle[iRowIndex][iColIndex] != 1234)
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
    int iMatPuzzle[4][4] = 
    {   
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,1234}
    };

    bool bIsRunning = true;

    cout << iMatPuzzle[2][4];

    while (bIsRunning)
    {
        cout << iMatPuzzle[2][4];
        displayPuzzle(iMatPuzzle);
        processTurn(iMatPuzzle);
    }

    return 0;
}