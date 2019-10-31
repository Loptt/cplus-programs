#include <bits/stdc++.h>
using namespace std;

#define maxK 100000

int K[maxK];

int main() {
    int b, k;

    cin >> b >> k;

    bool beven = b % 2 == 0;

    int eam = 0, oam = 0;
    for (int i = 0; i < k; i++) {
        cin >> K[i];
    }

    if (beven) {
        cout << (K[k-1] % 2 == 0 ? "even" : "odd") << endl;
        return 0; 
    }

    for (int i = 0; i < k; i++) {
        if (K[i] % 2 == 0) {
            eam++;
        } else {
            oam++;
        }
    }
    
    cout << (oam % 2 != 0 ? "odd" : "even") << endl;

    return 0;
}