#include <iostream>
#include <vector>
using namespace std;

struct Interruptor
{
    vector<int> lampControladas;
    vector<bool> lastState;
};

void showLamps(vector<bool> lamparas)
{
    for (int i = 1; i < lamparas.size(); ++i)
    {
        cout << lamparas[i] << " ";
    }
    cout << endl;
}

bool checkLamps(vector<bool> lamparas)
{
    for (int i = 1; i < lamparas.size(); ++i)
    {
        if (lamparas[i])
        {
            return false;
        }
    }

    return true;
}

bool checkIfInfinite(vector<Interruptor> &interruptores, vector<bool> lamparas, int inter)
{
    bool finished = interruptores[inter].lastState == lamparas;
    interruptores[inter].lastState = lamparas;

    return finished;
}

void switchLamps(vector<int> lampsToTurn, vector<bool> &lamps)
{
    for (int i = 0; i < lampsToTurn.size(); ++i)
    {
        //cout << "Lamps to switch: " << lampsToTurn[i] << " ";
        if (lamps[lampsToTurn[i]])
        {
            lamps[lampsToTurn[i]] = false;
        }
        else
        {
            lamps[lampsToTurn[i]] = true;
        }

        //cout << endl;
    }
}

int main()
{
    int cantInt, cantLamp;
    cin >> cantInt >> cantLamp;

    vector<bool> lamparas;

    for (int i = 0; i < cantLamp + 1; ++i)
    {
        lamparas.push_back(false);
    }

    int cantEncentidas;
    cin >> cantEncentidas;

    int numEncendida;

    for (int i = 0; i < cantEncentidas; ++i)
    {
        cin >> numEncendida;
        lamparas[numEncendida] = true;
    }

    vector<Interruptor> interruptores;

    int cantControladas;
    int lamparaControlada;

    for (int i = 0; i < cantInt; ++i)
    {
        Interruptor inter;
        cin >> cantControladas;

        for (int j = 0; j < cantControladas; ++j)
        {
            cin >> lamparaControlada;
            inter.lampControladas.push_back(lamparaControlada);
        }

        interruptores.push_back(inter);
    }

    Interruptor temp;

    interruptores.insert(interruptores.begin(), temp);

    bool finished = checkLamps(lamparas);

    int counter = 0;
    int intCounter = 1;

    int loopCounter = 0;

    while (!finished)
    {
        switchLamps(interruptores[intCounter].lampControladas, lamparas);

        finished = checkLamps(lamparas);

        if (checkIfInfinite(interruptores, lamparas, intCounter))
        {
            cout << -1 << endl;
            return 0;
        }

        if (intCounter == cantInt)
        {
            intCounter = 1;
            loopCounter++;
        }
        else
        {
            intCounter++;
        }

        counter++;

        //showLamps(lamparas);

        if (loopCounter > 10)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << counter << endl;

    return 0;
}
