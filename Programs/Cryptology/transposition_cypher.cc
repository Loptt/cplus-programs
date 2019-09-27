#include <iostream>
#include <cmath>
#include <algorithm>

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <-d (decrypt) | -e (encrypt)> <key>" << std::endl;
        return 1; 
    }

    bool de = argv[1][1] =='d';

    char key = argv[2][0];
    int n = 0;

    for (int i = 1; key != '\0'; i++) {
        n++;
        key = argv[2][i];
    }

    std::string input;

    int width, height, wIdx, hIdx;

    while (std::getline(std::cin, input)) {
        input.erase(std::remove(input.begin(), input.end(), ' '), input.end());

        width = n;
        height = (int) std::ceil((float) input.length() / (float) n);
        if (de) {
            width = (int) std::ceil((float) input.length() / (float) n);
            height = n;
        }

        char mat[height][width];

        wIdx = 0;
        hIdx = 0;

        for (int i = 0; i < input.length(); i++) {
            if (input[i] < 'A' || input[i] > 'Z') {
                // Ignore
            } else {
                mat[hIdx][wIdx++] = input[i];
                if (wIdx >= width) {
                    hIdx++;
                    wIdx = 0;
                }
            }
        }

        int count = 0;

        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                if (count >= input.length()) {
                    break;
                }

                std::cout << mat[j][i];
                count++;
            }
            if (count >= input.length()) {
                break;
            }
        }

        std::cout << std::endl;
    }

    return 0;
}