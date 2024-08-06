#include <iostream>
#include <stack>
#include <algorithm>

class Solution {
public:
    std::string reverseVowels(std::string s) {
       std::stack<char> vowelStack;
       std::string vowelString = "aeiouAEIOU";
       size_t position = 0;

        for (size_t i = 0; i < s.size(); i++) {
            position = vowelString.find(s[i]);
            if (position != std::string::npos)
                vowelStack.push(s[i]);
        }
        for (size_t j = 0; j < s.size(); j++) {
            position = vowelString.find(s[j]);
            if (position != std::string::npos) {
                s[j] = vowelStack.top();
                vowelStack.pop();
            }
        }
        std::cout << s << std::endl;
        return s;
    }
};

int main() {
    std::string word = "hello";
    Solution solution;

    solution.reverseVowels(word);
    std::cout << word << std::endl;
}