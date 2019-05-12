#include <iostream>
using namespace std;

class A
{
    int a;
    bool b;
    bool d;
    bool b;
    int c;

    //int func(int a);
    //int func2(int b);
};
/*
int A::func(int a) {
    return a;
}
*/
/*
int A::func2(int b) {
    return b;
}*/

int main() {
    cout << "Size of A: " <<  sizeof(A) << endl;
    cout << sizeof(bool) << endl;
    return 0;
}