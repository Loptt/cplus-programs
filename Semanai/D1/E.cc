#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n, x, y;
    cin >> n >> x >> y;
    long long int dw = x+y-2;
    long long int db = 2*n-x-y;
    cout << (db < dw ? "Black" : "White") << endl;
    return 0;
}