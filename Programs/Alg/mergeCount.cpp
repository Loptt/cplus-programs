#include <iostream>
#include <vector>

using namespace std;

int contComp=0;

//&function

void Une(vector<int> &d, int ini, int m, int fin){

    vector<int> aux;

    int i = ini, j = m + 1;
    while (i <= m && j <= fin) {
        if (d[i] < d[j]) {
            aux.push_back(d[i]);
            i++;
        }
        else {
            aux.push_back(d[j]);
            j++;
        }
        contComp++;
    }

    while (i <= m) {
        aux.push_back(d[i]);
        i++;
    }

    while (j <= fin) {
        aux.push_back(d[j]);
        j++;
    }

    for (int i  = ini, j = 0; i <= fin; i++, j++) {
        d[i] = aux[j];
    }

    //cout << endl << endl;
}

void MergeSort(vector<int> &d, int ini, int fin){
    if (ini < fin) {
        int mitad = (ini + fin) / 2;
        MergeSort(d, ini, mitad);
        MergeSort(d, mitad+1, fin);
        Une(d, ini,mitad,fin);
    }
}

int main(){
	int n;
	cin >> n;
	vector<int> datos;
    int num;
	for (int i=0; i<n; i++){
		cin>>num;
        datos.push_back(num);
	}
	MergeSort(datos, 0, n-1);
	cout << contComp<<endl;
	// for (int i=0; i<n; i++){
	// 	cout<<datos[i]<< " ";
	// }
    // cout << endl;
}