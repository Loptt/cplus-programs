#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    int clave, cantidad;
    double precio;
    char respuesta = 's';

    cout << "a) Pedir datos  b) Crear factura " << endl;
    cin >> respuesta;

    if (respuesta == 'a')
    {
        respuesta = 's';
        ofstream arSalida;
        arSalida.open("InvoiceData.txt");

        while (respuesta == 's')
        {
            cout << "Introduce la clave >> ";
            cin >> clave;
            cout << "Introduce la cantidad >> ";
            cin >> cantidad;
            cout << "Introduce el precio >> ";
            cin >> precio;

            cout << "Desea agregar otro artículo? >> ";
            cin >> respuesta;

            arSalida << clave << ' ' << cantidad << ' ' <<  precio << endl;
        }

        arSalida.close();
        
    }
    else
    {
        ifstream arEntrada;
        arEntrada.open("InvoiceData.txt");

        ofstream arSalida;
        arSalida.open("InvoiceFinal.txt");

        arSalida << setw(10) << "FACTURA" << endl;
        arSalida << setw(5) << "Clave" << setw(9) << "Cantidad" << setw(7) << "Precio" << endl;

        while (arEntrada >> clave >> cantidad >> precio)
        {
            arSalida << setw(5) << clave << setw(9) << cantidad << setw(7) << precio << endl;
        }

        arEntrada.close();
        arSalida.close();
    }



    return 0;

}