
#include <iostream>
#include <climits>
using namespace std;

int minimo(int i, int j, int D[52][52], int d[52]){
    int minVal = INT_MAX;
    for(int k=i; k<j; k++){
        if((D[i][k] + D[k+1][j] + d[j] - d[i-1])<minVal){
            minVal = D[i][k] + D[k+1][j] + d[j] - d[i-1];
        }
    }
    return minVal;
}

int algMatrices(int d[52], int n, int D[52][52]){
    //diagonal de ceros
    for (int i=1; i<=n; i++){
        D[i][i] = 0;
    }
    for (int diag=1; diag<= n-1; diag++){
        for (int i = 1; i<=n-diag; i++) {
            int j = i + diag;
            D[i][j] = minimo(i, j, D, d);
        }
    }
    return D[1][n];
}

int main(){
    int n,len;
    int D[52][52];
    int d[52];
    cin >> len;

    while (len != 0) {
        cin >> n;
        //llena arreglo de cortes
        d[0] = 0;
        for(int i=1; i<=n; i++){
            int x;
            cin >> x;
            d[i] = x;
        }
        d[n+1] = len;
        n++;
        
        cout << "The minimum cutting is " << algMatrices(d, n, D) << "."<< endl;
        cin >> len;
    }
    
}