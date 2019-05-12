/*
  Matricula: A01039919
  Nombre: Carlos Estrada
*/

#include <iostream>
#include <vector>

using namespace std;

bool llega(vector<int> &d){
  // Aquí va tu código.

    if (d.size() <= 1)
        return true; //asumiendo que el vacio si se puede

    if (d[0] == 0)
        return false;
    
    int zeroes = 0;
    int lastNum = d[0];
    bool inZero = false;

    for (int i = 1; i < d.size() - 1; i++) {
        if (d[i] == 0) {
            if (!inZero) {
                //Actualiza lastNum cuando se encuentra primera cadena de ceros
                lastNum = d[i-1];
                //Empieza cadena de ceros
                inZero = true;
                zeroes = 0;
            }
            zeroes++; //por cada cero suma 1
        }
        else {
            if (inZero) {
                inZero = false;
                //Si se sale de la cadena, checa que si la cantidad de ceros es igual o mayor al ultimo numero
                //antes de la cadena, entonces no es posible saltar la cadena
                if (lastNum <= zeroes) {
                    //entonces se regresa falso
                    return false;
                }
            }
        }
    }
    //Si sale del for loop sin problema entonces si se puede llegar al final
    return true;
}

int main(){
	int n;
	cin >> n;
	vector<int> datos(n);
	for (int i=0; i<n; i++){
		cin>>datos[i];
	}
  cout << (llega(datos)? "YES" : "NO" )<<endl;
}

/*
Ejemplo 1
4
1 2 3 1

Ejemplo 2
5
1 2 0 1 2

Ejemplo 3
5
1 1 0 1 2

*/