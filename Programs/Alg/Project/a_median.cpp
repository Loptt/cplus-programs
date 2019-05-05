#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

float median(const vector<int> &arr1, const vector<int> &arr2, int init1, int endt1, int init2, int endt2) {
    
    int index1 = (int) ceil((endt1+init1)/2.0);
    int index2 = (int) floor((endt2+init2)/2.0);

    if (arr1[index1] == arr2[index2]) {
        //cout << "Equal --" << index1 << ": " << arr1[index1] << " " << index2 << ": " << arr2[index2] << endl;
        return (float) arr1[index1];
    }

    //cout << endl<< " --" << index1 << ": " << arr1[index1] << "--" << index2 << ": " << arr2[index2] << endl;

    bool big2 = arr2[index2] > arr1[index1];

    int newinit1 = init1;
    int newinit2 = init2;

    int newendt1 = endt1;
    int newendt2 = endt2;

    int newi1 = 0;
    int newi2 = 0;

    if (big2) {
        if (arr1[index1+1] < arr2[index2]) {
            newinit1 = index1;
        } 
        if (arr2[index2-1] > arr1[index1]) {
            newendt2 = index2;
        }
    }
    else {
        if (arr1[index1-1] > arr2[index2]) {
            newendt1 = index1;
        } 
        if (arr2[index2+1] < arr1[index1]) {
            newinit2 = index2;
        }
    }

    int newindex1 = (int) ceil((newendt1+newinit1)/2.0);
    int newindex2 = (int) floor((newendt2+newinit2)/2.0);

    //cout << endl<< " --" << newindex1 << ": " << arr1[newindex1] << "--" << newindex2 << ": " << arr2[newindex2] << endl;

    if (newindex1 == index1 && newindex2 == index2) {
        return (arr1[index1] + arr2[index2]) / 2.0;
    }
    return median(arr1, arr2, newinit1, newendt1, newinit2, newendt2);
}

int main() {
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;

        vector<int> arr1;
        vector<int> arr2;
        int num;

        for (int i = 0; i < n; i++) {
            cin >> num;
            arr1.push_back(num);
        }

        for (int i = 0; i < n; i++) {
            cin >> num;
            arr2.push_back(num);
        }
        cout << "Median case " << i+1 << ": ";
        cout << fixed << setprecision(2) << median(arr1, arr2, 0, n-1, 0, n-1) << endl;
    }

    return 0;
}