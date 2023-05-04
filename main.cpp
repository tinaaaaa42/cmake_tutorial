#include <iostream>

#include "answer.hpp"

int main(int agrc, const char* argv[]) {
    int expected_answer = answer::expected_answer();
    for (;;) {
        std::cout << "What is the ultimate answer?" << std::endl;
        int answer;
        std::cin >> answer;
        if (answer == expected_answer) {
            std::cout << "Correct!" << std::endl;
            break;
        } else {
            std::cout << "Wrong!" << std::endl;
        }
    }
    return 0;
}
