#include <iostream>
#include <numeric>
#include <iostream>
#include <string>

class Solution {
public:
    std::string gcdOfStrings(std::string str1, std::string str2) {
        std::string output;
        size_t number;
        if (str1 + str2 != str2 + str1) {
            output = "";
            return output;
        }
        int a = str1.size();
        int b = str2.size();
        //check for the biggest number to pass as first parameter
        if (a > b) {
            number = std::gcd(a, b);
            output = str1.substr(0, number);
        }
        else {
            number = std::gcd(b, a);
            output = str2.substr(0, number);
        }
        return output;
    }
};

int main() {
    std::string word1 = "ABABAB";
    std::string word2 = "ABAB";

    Solution solution;
    std::string result = solution.gcdOfStrings(word1, word2);
    std::cout << result << std::endl;
    return 0;
}
