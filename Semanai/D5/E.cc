#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    string s, t;
    int let[26];
    while (q--) {
        cin >> s >> t;

        if (s == t) {
            cout << "YES" << endl;
            continue;
        }
        memset(let, 0, sizeof(let));

        for (int i = 0; i < s.length(); i++) {
            let[s[i]-'a']++;
        }

        bool found = false;

        for (int i = 0; i < t.length(); i++) {
            if (let[t[i]-'a']) {
                found = true;
                break;
            }
        }

        cout << (found?"YES":"NO") << endl;
    }
    return 0;
}