#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

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

void getKeyFromString(std::string keyString, std::vector<int> &key) {
    std::vector<std::string> tokens;
    std::istringstream iss(keyString);
    std::copy(std::istream_iterator<std::string>(iss), 
        std::istream_iterator<std::string>(), std::back_inserter(tokens));

    for (int i = 0; i < tokens.size(); i++) {
        key.push_back(std::stoi(tokens[i]));
    }
}

int main(int argc, char **argv) {
    bool de;
    checkUsage(argc, argv, de);

    std::string keyString(argv[2]);
    std::vector<int> key;

    getKeyFromString(keyString, key);

    if (de) {
        std::vector<int> newKey(key.size(), 0);
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
            if (input[i] < '0' || input[i] > '9') {
                // Ignore
            } else {
                result[i] = input[key[i]];
            }
        }

        std::cout << result << std::endl;
    }

    return 0;
}