#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <amount> <lenght>" << std::endl;
        exit(1);
    }

    srand(time(nullptr));

    int amount = atoi(argv[1]);
    int length = atoi(argv[2]);

    for (int i = 0; i < amount; i++) {
        for (int j = 0; j < length; j++) {
            std::cout << rand() % 2;
        }
        std::cout << std::endl;
    }

    return 0;
}