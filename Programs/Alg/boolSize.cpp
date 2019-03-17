#include <iostream>

using namespace std;

int main()
{
    cout << "Int size: " << sizeof(int) << endl;
    cout << "Bool size: " << sizeof(bool) << endl;
    cout << "char size: " << sizeof(char) << endl;

    char myBool = 0;

    myBool = myBool | 1; //sets 1st to true
    myBool = myBool & 253; //sets 2nd to false
    myBool = myBool | 4; //sets 3rd to true
    myBool = myBool | 8; //sets 4th to true
    myBool = myBool & 239; //sets 5th to false
    myBool = myBool | 32; //sets 6th to true

    cout << (int) myBool << endl;

    cout << (((myBool | 254) == 255) ? "First bool true" : "First bool false" ) << endl;
    cout << (((myBool | 253) == 255) ? "Second bool true" : "Second bool false" ) << endl;
    cout << (((myBool | 251) == 255) ? "Third bool true" : "Third bool false" ) << endl;
    cout << (((myBool | 247) == 255) ? "Fourth bool true" : "Fourth bool false" ) << endl;
    cout << (((myBool | 239) == 255) ? "Fifth bool true" : "Fifth bool false" ) << endl;
    cout << (((myBool | 223) == 255) ? "Sixth bool true" : "Sixth bool false" ) << endl;

    return 0;
}