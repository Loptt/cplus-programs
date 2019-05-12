#include <iostream>
#include <string>
using namespace std;

#define MAX 1001

int mat[MAX][MAX];

int max(int a, int b) {
    return a > b ? a : b;
}

int lcs(string s1, string s2) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            mat[i][j] = 0;
        }    
    }

    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i-1] != s2[j-1]) {
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
            }
            else {
                mat[i][j] = mat[i-1][j-1] + 1;
            }
        }
    }

    return mat[s1.length()][s2.length()];
}

int main() {
    int t;
    cin >> t;

    string s1;
    string s2;

    for (int i = 0; i < t; i++) {
        cin >> s1 >> s2;

        cout << "Case " << i + 1 << ": " << lcs(s1, s2) << endl;
    }
    return 0;
}