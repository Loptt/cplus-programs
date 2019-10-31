#include <bits/stdc++.h>
using namespace std;

#define maxN 100

int N[maxN];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> N[i];
    }

    int count = 0;

    int ridx = 0;

    for (int i = 0; i < n; i++) {
        if (N[i] <= k) {
            count++;
            ridx = i;
        } else {
            break;
        }
    }

    for (int i = n-1; i >= 0; i--) {
        if (N[i] <= k && i > ridx) {
            count++;
        } else {
            break;
        }
    }
    cout << count << endl;
    return 0;
}