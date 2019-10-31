#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long int x, y;
        cin >> x >> y;
        cout << (x - y != 1 ? "YES" : "NO") << endl;
    }
    return 0;
}