#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n, d;
    cin >> n >> d;

    string pads;
    cin >> pads;

    int count = 0;

    bool found = false;

    int i = 0;
    while (i < n-1) {
        for (int j = i+d; j > i; j--) {
            if (pads[j] == '1') {
                count++;
                found = true;
                i = j;
                break;
            }
        }

        if (!found) {
            cout << -1 << endl;
            return 0;
        }

        found = false;
    }

    cout << count << endl;

    return 0;
}