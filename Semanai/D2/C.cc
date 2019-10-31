#include <bits/stdc++.h>
using namespace std;

long int blue = 8, green = 5, red = 2;

int main() {
    int friends, sheets;
    cin >> friends >> sheets;

    long int tBlue, tGreen, tRed;
    tBlue = blue * friends;
    tGreen = green * friends;
    tRed = red * friends;

    long int total = 0;
    total += tBlue / sheets;
    if (tBlue % sheets) {
        total++;
    }

    total += tGreen / sheets;
    if (tGreen % sheets) {
        total++;
    }

    total += tRed / sheets;
    if (tRed % sheets) {
        total++;
    }
    
    cout << total << endl;
    return 0;
}