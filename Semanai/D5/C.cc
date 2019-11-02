#include <bits/stdc++.h>
using namespace std;

#define maxN 550
#define maxM 550
#define maxA 100100

int mat[maxN][maxM];

int primes[maxA];

bool prime(int x) {

    if (primes[x] != 0) {
        return primes[x] == 1;
    }

    if (x == 0 || x == 1) {
        return false;
    }
    if (x == 2)
        return true;

    for (int i = 2; i <= x/2; i++) {
        if (x % i == 0) {
            primes[x] = 2;
            return false;
        }
    }

    primes[x] = 1;

    return true;
}

int nextprime(int n) {
    int i = n;

    while (true) {
        if (prime(i))
            return i-n;
        i++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    memset(primes, 0, sizeof(primes));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    vector<int> rows;
    vector<int> cols;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }

        cout << endl;
    }*/

    int count = 0;

    //Rows
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            count += nextprime(mat[i][j]);
        }
        rows.push_back(count);
        count = 0;
    }

    //cols
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            count += nextprime(mat[j][i]);
        }
        cols.push_back(count);
        count = 0;
    }
/*
    for (int i = 0; i < rows.size(); i++) {
        cout << rows[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < cols.size(); i++) {
        cout << cols[i] << " ";
    }
    cout << endl;
*/

    cout << min(*min_element(rows.begin(), rows.end()), *min_element(cols.begin(), cols.end())) << endl;
    return 0;
}