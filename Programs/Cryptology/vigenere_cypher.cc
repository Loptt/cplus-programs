#include <iostream>
#include <string>
#include <vector>

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <-d (decrypt) | -e (encrypt)> <key>" << std::endl;
        return 1; 
    }

    bool de = argv[1][1] =='d';

    std::vector<int> shifts;

    char key = argv[2][0];

    for (int i = 1; key != '\0'; i++) {
        shifts.push_back(key - 'A');
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
            if (input[i] < 'A' || input[i] > 'Z') {
                // Ignore
            } else {
                char result = (char) (((input[i] - 'A' + shifts[shiftIdx % shifts.size()]) % 26) + 'A');
                if (result < 'A') {
                    result += 26;
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