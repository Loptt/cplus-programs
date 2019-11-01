#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, v;
    cin >> n >> v;

    if (v >= n) {
        cout << n << endl;
        return 0;
    }

    cout << v + ((n-v)*(n-v+1))/2 -1 << endl;
    return 0;
}