#include <iostream>
#include <vector>
using namespace std;

long long int catalan(int n) {
    vector<long long int> cats;

    if (!n)
        return 1;
    
    cats.push_back(1);

    long long int sum = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            sum += cats[j] * cats[i -1 - j];
        }

        cats.push_back(sum);
        sum = 0;
    }

    return cats[n];
}

int main() {
    int n;
    cin >> n;

    cout << catalan(n) << " BTrees" << endl;

    return 0;
}