#include <bits/stdc++.h>
using namespace std;

#define maxN 100
#define maxC 101

int N[maxN], C[maxC];

int main() {
    int n, k;
    cin >> n >> k;

    memset(C, 0, sizeof(C));

    for (int i = 0; i < n; i++) {
        cin >> N[i];
    }

    int count = 0;

    bool possible = false;
    vector<int> ids;

    for (int i = 0; i < n; i++) {
        if (C[N[i]] == 0) {
            count++;
            ids.push_back(i);
        }
        C[N[i]]++;

        if (count >= k) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "YES" << endl;
        for (int i = 0; i < ids.size(); i++) {
            cout << ids[i]+1 << " ";
        }

        cout << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}