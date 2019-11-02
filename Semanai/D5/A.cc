#include <bits/stdc++.h>
using namespace std;

bool diff(string s) {
    bool nums[10];

    memset(nums, 0, sizeof(nums));

    //cout << "NUm checking " << s;

    for (int i = 0; i < s.length(); i++) {
        if (nums[s[i]-'0']) {
            //cout << " NO DIFF" << endl;
            return false;
        } else {
            nums[s[i]-'0'] = true;
        }
    }

    //cout << " YES DIFF" << endl;

    return true;
}

int main() {
    int l, r;
    cin >> l >> r;

    for (int i = l; i <= r; i++) {
        if (diff(to_string(i))) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}