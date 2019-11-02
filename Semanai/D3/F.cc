#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;

    string input;

    cin >> input;

    int maxa = 0;
    int curr = 0;
    int j = 0;

    for (int i = 0; i < input.length(); i++) {
        while (j < n && curr <= k) {
            //cout << i << "-" << j << " ";
            if (input[j] == 'b') {
                curr++;
            }

            j++;
        }

        if (j >= n && curr > k) {
            maxa = max(maxa, j - i-1);
        } else if (j != n) {
            maxa = max(maxa, j - i-1);
        } else {
            maxa = max(maxa, j - i);
        }
/*
        if (j != n) {
            maxa = max(maxa, j - i-1);
        } else {
            maxa = max(maxa, j - i);
        }
*/
        if (input[i] == 'b') {
            curr--;
        }
    }

    curr = 0;
    j = 0;
    int maxb = 0;

    for (int i = 0; i < input.length(); i++) {
        while (j < n && curr <= k) {
            if (input[j] == 'a') {
                curr++;
            }

            j++;
        }

        if (j >= n && curr > k) {
            maxb = max(maxb, j - i-1);
        } else if (j != n) {
            maxb = max(maxb, j - i-1);
        } else {
            maxb = max(maxb, j - i);
        }

       /* if (j != n) {
            maxb = max(maxb, j - i-1);
        } else {
            maxb = max(maxb, j - i);
        }*/

        if (input[i] == 'a') {
            curr--;
        }
    }
    //cout << "Max a-" << maxa << " Max b-" << maxb << endl;

    cout << max(maxa, maxb) << endl;
    
    return 0;
}