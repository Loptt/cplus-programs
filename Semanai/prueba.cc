#include <bits/stdc++.h>
using namespace std;

#define maxN 100
#define maxA 101

int a[maxN], c[maxA];

int main() {
    int q, n;
    cin >> q;

    while (q--) {
        cin >> n;
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            c[a[i]]++;
        }
        
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (a[i+1] == a[i]+1)
                ans = 2;
        }

        cout << ans << endl;
    }

    return 0;
}