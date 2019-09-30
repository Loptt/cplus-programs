#include <iostream>
#include <cmath>
#include <algorithm>

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
        std::cerr << "Decrypt not yet available" << std::endl;
        return 1;
    } else if (argv[1][1] == 'e') {
        de = false;
    } else {
        std::cerr << "Usage: " << argv[0] << " <-d (decrypt) | -e (encrypt)> <shift>" << std::endl;
        return 1;
    }
    
    int key = atoi(argv[2]);

    std::string input;

    while (std::getline(std::cin, input)) {

        for (int i = 0; i < input.length(); i++) {
            if (input[i] < 'A' || input[i] > 'Z') {
                // Ignore
            } else {
                std::cout << (char) ((((input[i] - 'A') * key)  % 26) + 'A');
            }
        }
        std::cout << std::endl;
    }

    return 0;
}