#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n;
    cin >> n;

    long long int i = 1;

    bool found = false;

    while (i*(i+1)/2 < n) {
        long long int x = i*(i+1)/2;
        long long int y = n - x;

        //cout << "X " << x << " -- Y " << y;
        
        long long int sq = round(sqrt(1+8*y));
        //cout << " SQ " << sq << endl;

        if (sq * sq != (1+8*y)) {
            i++;
            continue;
        }

        long long int res = sq-1;

        if (res % 2 != 0) {
            i++;
            continue;
        }

        found = true;
        break;
    }
    cout << (found?"YES":"NO") << endl;
    return 0;
}