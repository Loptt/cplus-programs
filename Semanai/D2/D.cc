#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    
    while (q--) {
        signed long long int l, r;
        cin >> l >> r;
        l--;

        signed long long int sumRange = r*(r+1)/2 - l*(l+1)/2;
        signed long long int evenR = (r%2!=0?r+1:r);
        signed long long int evenL = (l%2!=0?l+1:l);        
        signed long long int sumodds = (evenR*evenR/4-evenL*evenL/4);
        signed long long int total = sumRange - 2*sumodds;
        cout << total << endl;
    }
    return 0;
}