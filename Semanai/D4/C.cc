#include <bits/stdc++.h>
using namespace std;

#define maxN 100010

long long int N[maxN];

int main() {
    long long int n;
    cin >> n;

    long long int neg = 0, zeros = 0;

    for (int i = 0; i < n; i++) {
        cin >> N[i];

        if (N[i] < 0)
            neg++;
        if (N[i] == 0) {
            zeros++;
        }
    }

    long long int total = 0;

    for (long long int i = 0; i < n; i++) {
        total += abs(abs(N[i]) - 1);
    }

    if (zeros == 0 && (neg % 2 == 1)) 
        total += 2;

    cout << total << endl;

    return 0;
}