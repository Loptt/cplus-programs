#include <bits/stdc++.h>
using namespace std;

#define maxN 100

int N[maxN];

int main() {
    int n;
    cin >> n;

    int positive = 0, negative = 0, zero = 0;

    int limit =  n / 2;
    if (n % 2 == 1)
        limit++;
    
    for (int i = 0; i < n; i++) {
        cin >> N[i];

        if (N[i] > 0) positive++;
        else if (N[i] < 0) negative++;
        else zero++;
    }

    // cout << "Positive " << positive << " Negative " << negative << " limit " << limit << endl;

    if (positive >= limit)
        cout << 1 << endl;
    else if (negative >= limit)
        cout << -1 << endl;
    else 
        cout << 0 << endl;
    return 0;
}