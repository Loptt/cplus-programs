#include <bits/stdc++.h>
using namespace std;

#define maxN 100010

int N[maxN];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> N[i];
    }

    vector<long long int> ranges;

    long long int acc = 1;

    for (int i = 0; i < n; i++) {
        ranges.push_back(acc);
        acc += N[i];
    }
/*
    for (int i = 0; i < ranges.size(); i++)
        cout << ranges[i] << " ";
    cout << endl;

*/

    int m;
    cin >> m;

    while (m--) {
        long long int q;
        cin >> q;
        vector<long long int>::iterator it = upper_bound(ranges.begin(), ranges.end(), q);
        if (it == ranges.end()) {
            cout << n << endl;
        } else {
            cout << (it - ranges.begin()) << endl;
        }
    }
    return 0;
}