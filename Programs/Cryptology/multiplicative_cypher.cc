#include <iostream>
#include <cmath>
#include <algorithm>

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <-d (decrypt) | -e (encrypt)> <key>" << std::endl;
        return 1; 
    }

    bool de = argv[1][1] =='d';
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