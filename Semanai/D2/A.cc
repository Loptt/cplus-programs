#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        string query;
        int n;
        cin >> n >> query;

        if (query.length() < 3) {
            if (query[0] >= query[1]) {
                cout << "NO" << endl;
                continue;
            } else {
                cout << "YES" << endl;
                cout << "2" << endl;
                cout << query[0] << " " << query[1] << endl;
                continue;
            }
        }

        cout << "YES" << endl;
        cout << "2" << endl;
        cout << query[0] << " " << query.substr(1) << endl;
    }
}