#include <iostream>
using namespace std;

int main() {
    long long int n, k, nCombinations = 0;

    cin >> n >> k;
    if (n >= k) {
        cout << k / 2 << endl;
        return 0;
    }

    cout << k / 2 - (k - n - 1) << endl;
    return 0; 
}