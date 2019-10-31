#include <bits/stdc++.h>
using namespace std;

int main() {
    int andrew, dimitri, michal;
    cin >> andrew >> dimitri >> michal;

    int green, purple, black;
    cin >> green >> purple >> black;

    if (green + purple + black < andrew + dimitri + michal) {
        cout << "NO" << endl;
        return 0;
    }

    if (green < andrew) {
        cout << "NO" << endl;
        return 0;
    }

    if (green + purple - andrew < dimitri) {
        cout << "NO" << endl;
        return 0;
    }

    if (green + purple + black - andrew - dimitri < michal) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    return 0;
}