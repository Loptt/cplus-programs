#include <bits/stdc++.h>
using namespace std;

#define maxN 120
int N[maxN];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> N[i];
    }

    /*for (int i = 0; i < n; i++) {
        cout << N[i] << endl;
    }*/

    int i = 0;
    while (N[i] < N[i+1] && i < n) {
        i++;
    }

    while (N[i] == N[i+1] && i < n) {
        i++;
    }

    while (N[i] > N[i+1] && i < n) {
        i++;
    }   

    cout << (i == n ? "YES" : "NO") << endl;

    return 0;
}