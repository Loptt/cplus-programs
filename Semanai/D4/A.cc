#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n;
    cin >> n;

    int total = 0;
    total = n / 100;
    n = n % 100;

    total += n / 20;
    n = n % 20;

    total += n / 10;
    n = n % 10;

    total += n / 5;
    n = n % 5;

    total += n / 1;
    n = n % 1;

    cout << total << endl;

}