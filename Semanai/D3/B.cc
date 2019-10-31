#include <bits/stdc++.h>
using namespace std;

#define maxN 120

int N[maxN];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    cin >> n;

    N[0] = 0;
    N[n+1] = 1001;
    
    for (int i = 1; i < n+1; i++) {
        cin >> N[i];
    }

    bool succ = false;
    int count = 0;
    int maxc = 0;

    for (int i = 1; i < n+1; i++) {
        //cout << "N: " << N[i] << endl;
        if (N[i]-1 == N[i-1] && N[i]+1 == N[i+1])
            count++;
        else {
            //cout << "NO EQ " << N[i-1] << " " << N[i] << " " <<  N[i+1] << endl;
            maxc = max(count, maxc);
            count = 0;
        }
    }

    maxc = max(count, maxc);

    cout << maxc << endl;
    return 0;
}