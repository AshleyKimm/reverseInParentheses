#include <iostream>

int main();
std::string solution(std::string);

int main() {
    std::string input;

    std::cout << "Enter a string with parentheses: ";
    std::cin >> input;
    std::string answer = solution(input);
    std::cout << "After reversed: " << answer << std::endl;
}


std::string solution(std::string inputString) {
    
    for (int i{0}; i < inputString.size(); i ++) {
        
        // Searches for the index of ')' and moves to the left to
        // search for '('
        if (inputString[i] == ')') {
            int close = i;
            inputString.erase(close, 1);
            for (int open {close - 1}; open >= 0; open --) {
                
                // Searches for the index of '('
                if (inputString[open] == '(') {
                    for (int k{1}; (open + k) < (close - k); k ++) {

                        // Bubblesort method to reverse letters inside brackets
                        char temp{};
                        temp = inputString[close - k];
                        inputString[close - k] = inputString[open + k];
                        inputString[open + k] = temp;
                    }
                    inputString.erase(open, 1);
                    break;
                }
                --i;
            }
        }
    }
    return inputString;
}

