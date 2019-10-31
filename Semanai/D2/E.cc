#include <bits/stdc++.h>
using namespace std;

bool vowel(char a) {
    switch(a) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}

int main() {
    string a, b;
    cin >> a >> b;

    if (a.length() != b.length()) {
        cout << "No" << endl;
        return 0;
    }

    for(int i = 0; i < a.length(); i++) {
        if (vowel(a[i]) ^ vowel(b[i])) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}