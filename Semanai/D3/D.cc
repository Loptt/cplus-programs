#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string input;
    cin >> input;

    if (input.length() < 2) {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i < input.length()-1; i++) {
        if (input[i] != input[i+1]) {
            cout << "YES" << endl;
            cout << input[i] << input[i+1] << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}