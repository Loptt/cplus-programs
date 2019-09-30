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
        de = true;
    } else if (argv[1][1] == 'e') {
        de = false;
    } else {
        std::cerr << "Usage: " << argv[0] << " <-d (decrypt) | -e (encrypt)> <shift>" << std::endl;
        return 1;
    }

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

        while (wIdx < width) {
            mat[hIdx][wIdx++] = ' '; 
        }

        int count = 0;

        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                if (count >= input.length()) {
                    break;
                }

                if (mat[j][i] != ' ') {
                    std::cout << mat[j][i];
                    count++;
                }
            }
            if (count >= input.length()) {
                break;
            }
        }

        std::cout << std::endl;
    }

    return 0;
}