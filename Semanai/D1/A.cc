#include <bits/stdc++.h>
using namespace std;

#define maxN 100
#define maxT 100000

int main() {
    int n, t;
    cin >> n >> t;

    int routes[maxN][2];

    for (int i = 0; i < n; i++) {
        cin >> routes[i][0];
        cin >> routes[i][1];
    }

    int wait[maxN];

    int minW = INT_MAX;
    int minIdx = 0;

    for (int i = 0; i < n; i++) {
        int x = 0;
        if (t > routes[i][0]) {
            x = ceil((float) (t -routes[i][0]) / (float) routes[i][1]);
        }

        int func = routes[i][1]*x + routes[i][0];

        if (func == t) {
            //cout << "Igual ";
            wait[i] = 0;
        } else {
            //cout << "No ig t=" << t << " func=" << func;
            wait[i] = func - t;
        }

        if (wait[i] < minW) {
            minW = wait[i];
            minIdx = i;
        }

        //cout <<" X: " << x <<  " Wait: " << wait[i] << endl;
    }

    //cout << "Min bus " << minIdx+1 << endl;

    cout << minIdx+1 << endl;

    return 0;
}