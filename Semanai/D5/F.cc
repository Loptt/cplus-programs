#include <bits/stdc++.h>
using namespace std;

#define maxN 1100

int N[maxN];

bool checkFront(int &i, int &j) {
    while (N[j] != 1) {
        //cout << "i--" << i << " j--" << j << endl;
        if (j == i) {
            if (N[j] != 1) {
                return false;
            } else {
                return true;
            }
        }

        j--;
    }

    return true;
}

bool checkBack(int &i, int &j) {
    while (N[j] != 1) {
        //cout << "i--" << i << " j--" << j << endl;
        if (j == i) {
            if (N[j] != 1) {
                return false;
            } else {
                return true;
            }
        }

        j++;
    }

    return true;
}

int main() {
    int n, r;
    cin >> n >> r;
    
    for(int i = 0; i < maxN; i++) {
        cin >> N[i];
    }

    int count = 0;

    int i = 0, j = 0;

    j = i + r -1;

    bool found = true;

    while (i < n) {
        if (checkFront(i, j)) {
            count++;
            i = j + r;
            j = i + r - 1;
            if (j >= n)
                j = n-1;
            continue;
        }

        j = i - r + 1;
        if (checkBack(i, j)) {
            count++;
            i = j + r;
            j = i + r - 1;
            if (j >= n)
                j = n-1;
            continue;
        }

        found = false;
        break;
    }

    cout << (found?count:-1) << endl;
    
    return 0;
}