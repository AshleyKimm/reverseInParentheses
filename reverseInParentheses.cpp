#include <iostream>


int main();
std::string solution(std::string);

int main() {
    std::string input;
    std::cout << "Enter a string with parentheses: " << std::endl;
    std::cin >> input;
    std::string answer = solution(input);
    std::cout << answer << std::endl;
}
std::string solution(std::string inputString) {
    for (int i{0}; i < inputString.size(); i ++) {
        
        if (inputString[i] == ')') {
            int close = i;
            std::cout << "Before erased : " << inputString << std::endl;
            inputString.erase(close, 1);
            for (int open {close - 1}; open >= 0; open --) {
                
                if (inputString[open] == '(') {
                    for (int k{1}; (open + k) < (close - k); k ++) {
                            char temp{};
                            temp = inputString[close - k];
                            inputString[close - k] = inputString[open + k];
                            inputString[open + k] = temp;
                    }
                    inputString.erase(open, 1);
                    break;
                    std::cout << "after erased : " << inputString << std::endl;
                }
                --i;
            }
        }
    }
    return inputString;
}

