#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int k, n;
    cin >> n >> k;

    long long int x = (((int) sqrt((double) (9 + 8*(k+n)))) - 3) / 2;
    long long int total = (x*(x+1))/2;
    cout << total - k << endl;
    
    return 0;
}