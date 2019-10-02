#include <iostream>
#include <string>
#include <vector>

void checkUsage(int argc, char **argv, bool &de) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <-d (decrypt) | -e (encrypt)> <key>" << std::endl;
        exit(1);
    }

    if (argv[1][0] != '-') {
        std::cerr << "Usage: " << argv[0] << " <-d (decrypt) | -e (encrypt)> <shift>" << std::endl;
        exit(1);
    }

    if (argv[1][1] == 'd') {
        de = true;
    } else if (argv[1][1] == 'e') {
        de = false;
    } else {
        std::cerr << "Usage: " << argv[0] << " <-d (decrypt) | -e (encrypt)> <shift>" << std::endl;
        exit(1);
    }
}

int main(int argc, char **argv) {
    bool de;
    checkUsage(argc, argv, de);

    std::vector<int> key;

    char k = argv[2][0];

    for (int i = 1; k != '\0'; i++) {
        key.push_back(k - '0');
        k = argv[2][i];
    }

    if (de) {
        std::vector<int> newKey(5, 0);
        for (int i = 0; i < key.size(); i++) {
            newKey[key[i]] = i;
        }

        key = newKey;
    }

    std::string input;
    std::string result;

    while (std::getline(std::cin, input)) {
        result = input;
        for (int i = 0; i < input.length(); i++) {
            if (input[i] < '0' || input[i] > '1') {
                // Ignore
            } else {
                result[i] = input[key[i]];
            }
        }

        std::cout << result << std::endl;
    }

    return 0;
}