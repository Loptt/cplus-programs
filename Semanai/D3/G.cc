#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    string input;
    int n;
    cin >> n;
    cin.ignore();
    //cin.ignore();
    getline(cin, input);

    int caps = 0;
    int maxcaps = 0;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] <= 'Z' && input[i] >= 'A') {
            caps++;
        }
        //cout << caps << endl;

        if (input[i] == ' ') {
            maxcaps = max(caps, maxcaps);
            caps = 0;
        }
    }

    maxcaps = max(caps, maxcaps);

    cout << maxcaps << endl;
    return 0;
}