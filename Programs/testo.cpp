#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream variable;
    variable.open("informacion.txt");

    char numero;
    while (variable >> numero)
    {
       if (variable >> endl)
        {
            cout << "hola" << endl;
        }
    }

    variable.close();
    return ;
}