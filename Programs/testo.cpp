#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream variable;
    variable.open("informacion.txt");

    int numero = 0;

    for (int i = 0; i < 10; ++i)
    {
        variable >> numero;
        cout << numero << endl;
    }

    variable.close();
    return 0;
}