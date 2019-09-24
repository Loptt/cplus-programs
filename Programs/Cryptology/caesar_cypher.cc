#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    if (argc != 4) {
        cout << "Usage: " << argv[0] << " <-d (decrypt) | -e (encrypt)> <text> <shift>" << endl;
        return 1; 
    }
    bool de = argv[1][1] =='d';
    cout << argv[1] << endl;
    char input = argv[2][0];
    int shift = atoi(argv[3]);

    if (de) {
        shift = shift * -1;
    }

    for (int i = 1; input != '\0'; i++) {
        if (input == ' ') {
            cout << " ";
        } else {
            char result = (char) (((input - 'A' + shift) % 26) + 'A');
            if (result < 'A') {
                result += 26;
            }
            cout << result;
        }
        input =  argv[2][i];
    }

    cout << endl;
    return 0;
}