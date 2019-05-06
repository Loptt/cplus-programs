#include <iostream>
#include <vector>
using namespace std;

#define MAX 2000

bool mat[MAX][MAX];

bool isPossible(const vector<int> &train1, const vector<int> &train2, const vector<int> &dreamtrain, int n1, int n2) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            mat[i][j] = false;
        }
    }

    mat[0][0] = true;

    for (int i = 1; i <= train1.size(); i++) {
        if (mat[i-1][0] && dreamtrain[i-1] == train1[i-1]) {
            mat[i][0] = true;
        }
    }

    for (int i = 1; i <= train2.size(); i++) {
        if (mat[0][i-1] && dreamtrain[i-1] == train2[i-1]) {
            mat[0][i] = true;
        }
    }

    for (int i = 1; i <= train1.size(); i++) {
        for (int j = 1; j <= train2.size(); j++) {
            if ((mat[i-1][j] && dreamtrain[i+j-1] == train1[i-1]) || (mat[i][j-1] && dreamtrain[i+j-1] == train2[j-1])) {
                mat[i][j] = true;
            }
        }
    }

    return mat[train1.size()][train2.size()];
}

int main() {
    int n1, n2;

    vector<int> train1;
    vector<int> train2;
    vector<int> dreamtrain;

    cin >> n1 >> n2;

    while (n1 != 0 || n2 != 0) {
        int num;

        for (int i = 0; i < n1; i++) {
            cin >> num;
            train1.push_back(num);
        }

        for (int i = 0; i < n2; i++) {
            cin >> num;
            train2.push_back(num);
        }

        for (int i = 0; i < n1 + n2; i++) {
            cin >> num;
            dreamtrain.push_back(num);
        }

        cout << (isPossible(train1, train2, dreamtrain, n1, n2) ? "possible" : "not possible") << endl;

        cin >> n1 >> n2;
        train1.clear();
        train2.clear();
        dreamtrain.clear();
    }
    
    return 0;
}