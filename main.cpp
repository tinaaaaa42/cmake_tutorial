#include <iostream>

#include <answer/answer.hpp>

int main(int agrc, const char* argv[]) {
    for (;;) {
        std::cout << "What is the ultimate answer?" << std::endl;
        std::string answer;
        std::cin >> answer;
        auto expected_answer = answer::expected_answer();
        if (answer == expected_answer) {
            std::cout << "Correct!" << std::endl;
            break;
        } else {
            std::cout << "Wrong!" << std::endl;
        }
    }
    return 0;
}
