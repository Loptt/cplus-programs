#include <iostream>
#include <string>

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <-d (decrypt) | -e (encrypt)> <shift>" << std::endl;
        return 1; 
    }
    bool de = argv[1][1] =='d';
    int shift = atoi(argv[2]);

    if (de) {
        shift = shift * -1;
    }

    std::string input;

    while (std::getline(std::cin, input)) {
        for (int i = 0; i < input.length(); i++) {
            if (input[i] < 'A' || input[i] > 'Z') {
                // Ignore
            } else {
                char result = (char) (((input[i] - 'A' + shift) % 26) + 'A');
                if (result < 'A') {
                    result += 26;
                }
                std::cout << result;
            }
        }

        std::cout << std::endl;
    }

    return 0;
}