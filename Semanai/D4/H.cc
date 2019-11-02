#include <bits/stdc++.h>
using namespace std;

#define maxDP 10000
int dp[maxDP];

int a, b, c;

int gets(int n) {
    if (n == 0) {
        return 0;
    }  
    if (dp[n] > INT_MIN)
        return dp[n];

    int maxa = INT_MIN;

    if (n-a >= 0) {
        maxa = max(gets(n-a)+1, maxa);
    }
    if (n-b >= 0) {
        maxa = max(gets(n-b)+1, maxa);
    }
    if (n-c >= 0) {
        maxa = max(gets(n-c)+1, maxa);
    }
    
    dp[n] = maxa;
    return maxa;
}

int main() {
    int n;
    cin >> n >> a >> b >> c;

    if (a == 1 || b == 1 || c == 1) {
        cout << n << endl;
        return 0;
    }

    for (int i = 0; i < maxDP; i++) {
        dp[i] = INT_MIN;
    }

    cout << gets(n) << endl;

    return 0;
}