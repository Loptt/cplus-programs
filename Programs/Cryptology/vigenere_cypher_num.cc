#include <iostream>
#include <string>
#include <vector>

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <-d (decrypt) | -e (encrypt)> <key>" << std::endl;
        return 1; 
    }

    if (argv[1][0] != '-') {
        std::cerr << "Usage: " << argv[0] << " <-d (decrypt) | -e (encrypt)> <shift>" << std::endl;
        return 1;
    }

    bool de;
    if (argv[1][1] == 'd') {
        de = true;
    } else if (argv[1][1] == 'e') {
        de = false;
    } else {
        std::cerr << "Usage: " << argv[0] << " <-d (decrypt) | -e (encrypt)> <shift>" << std::endl;
        return 1;
    }

    std::vector<int> shifts;

    char key = argv[2][0];

    for (int i = 1; key != '\0'; i++) {
        shifts.push_back(key - '0');
        key = argv[2][i];
    }

    if (de) {
        for (int i = 0; i < shifts.size(); i++) {
            shifts[i] = shifts[i] * -1;
        }
    }

    std::string input;
    int shiftIdx = 0;

    while (std::getline(std::cin, input)) {
        for (int i = 0; i < input.length(); i++) {
            if (input[i] < '0' || input[i] > '9') {
                // Ignore
            } else {
                char result = (char) (((input[i] - '0' + shifts[shiftIdx % shifts.size()]) % 10) + '0');
                if (result < '0') {
                    result += 10;
                }
                std::cout << result;
                shiftIdx++;
            }
        }

        shiftIdx = 0;
        std::cout << std::endl;
    }

    return 0;
}