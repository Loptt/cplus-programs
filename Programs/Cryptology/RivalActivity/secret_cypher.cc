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

    char k = argv[2][0];
    std::string key = "";

    for (int i = 0; k != '\0'; i++) {
        key += argv[2][i];
        k = argv[2][i];
    }

    int mult = (key[0] - 'A' + 1) * (key[1] - 'A' + 1);
    std::vector<int> shifts;

    for (int i = 2; i < key.size(); i++) {
        shifts.push_back((key[i] - 'A') * mult);
    }

    if (de) {
        for (int i = 0; i < shifts.size(); i++) {
            shifts[i] = shifts[i] * -1;
        }
    }

    std::string input;
    int sIndex = 0;

    while (std::getline(std::cin, input)) {
        for (int i = 0; i < input.length(); i++) {
            if (input[i] < 'A' || input[i] > 'Z') {
                // Ignore
            } else {
                char result = (char) (((input[i] - 'A' + shifts[sIndex % shifts.size()]) % 26) + 'A');
                if (result < 'A') {
                    result += 26;
                }
                std::cout << result;
                sIndex++;
            }
        }

        std::cout << std::endl;
    }

    return 0;
}