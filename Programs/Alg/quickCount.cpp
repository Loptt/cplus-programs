#include <iostream>
#include <vector>

using namespace std;

int contComp=0;

//&function

void Particion(vector<int> &d, int ini, int fin, int &pivote){
	int elempivote = d[ini];
    int j = ini, tmp = 0;

    for (int i = ini + 1; i <= fin; i++) {
        if (d[i] < elempivote) {
            j++;
            tmp = d[j];
            d[j] = d[i];
            d[i] = tmp;
        }

        contComp++;
    }

    pivote = j;
    tmp = d[ini];
    d[ini] = d[pivote];
    d[pivote] = tmp;
}

void QuickSort(vector<int> &d, int ini, int fin){
    if (ini < fin) {
        int mitad = (ini + fin) / 2;
        int pivote = ini;
        Particion(d, ini, fin, pivote);
        QuickSort(d, ini, pivote-1);
        QuickSort(d, pivote+1, fin);
    }

}

int main(){
	int n;
	cin >> n;
	vector<int> datos(n);
	for (int i=0; i<n; i++){
		cin>>datos[i];
	}
	QuickSort(datos, 0, n-1);
	cout << contComp<<endl;
	
	// for (int i=0; i<n; i++){
	// 	cout<<datos[i]<< " ";
	// } 
	// cout << endl;
	
}