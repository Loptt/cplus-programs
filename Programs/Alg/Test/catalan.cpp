#include <iostream>
#include <vector>
using namespace std;

int catalan(int n) {
    vector<int> cats;
    
    cats.push_back(1);

    if (!n)
        return 1;

    int sum = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            sum += cats[j] * cats[i - 1 - j];
        }

        cats.push_back(sum);
        sum = 0;
    }

    return cats[n];
}

int main() {
    int n; 
    cout << "Seq num: ";
    cin >> n;

    cout << "Catalan num: " << catalan(n) << endl;
    return 0;
}