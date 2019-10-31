#include <bits/stdc++.h>
using namespace std;

#define maxN 100001

int N[maxN];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> N[i];
    }

    int maxa = 0;
    int ones = 0;
    int twos = 0;
    
    bool inOnes = false;
    bool inTwos = false;

    for (int i = 0; i < n; i++) {
        if (N[i] == 1) {
            if (!inOnes) {
                ones = 0;
            }
            inOnes = true;
            inTwos = false;
            ones++;

            
        }
        if (N[i] == 2) {
            if (!inTwos) {
                twos = 0;
            }
            inTwos = true;
            inOnes = false;
            twos++;
        }

        maxa = max(min(ones, twos), maxa);
    }

    cout << maxa*2 << endl;
    return 0;
}