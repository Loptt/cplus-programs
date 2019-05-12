#include <iostream>
#include <vector>
using namespace std;

int fib(int n) {
    vector<int> fibs;

    fibs.push_back(1);
    fibs.push_back(1);

    if (n < 2)
        return 1;

    for (int i = 2; i < n; i++) {
        fibs.push_back(fibs[i-1] + fibs[i-2]);
    }

    return fibs[n-1];
}

int main() {
    int n;
    cout << "Seq num: ";
    cin >> n;

    cout << "Fib num: " << fib(n) << endl;
    return 0;
}