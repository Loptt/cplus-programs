#include <bits/stdc++.h>
using namespace std;

#define maxN 100010

long long int N[maxN];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> N[i];
    }

    int count = 1; 
    int maxa = 1;

    for (int i = 0; i < n-1; i++) {
       // cout << " Count " << count << " " << N[i] << "-" << N[i+1];
        if (N[i] <= N[i+1]) {
            count++;
            //cout << " Increasing" << endl;
        }
        else {
            maxa = max(count, maxa);
            count = 1;
        }
    }

    maxa = max(count, maxa);

    cout << maxa << endl;

    return 0;
}