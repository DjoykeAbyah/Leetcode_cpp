#include <iostream>
#include <string>

//divide largest by smallest 
//replace smallest by remainder and largest by smallest
//keep doing this until smalles (b) = 0, a = the gcd;
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

class Solution {
    
    public:
        std::string gcdOfStrings(std::string str1, std::string str2) {
            if (str1 + str2 != str2 + str1) {
                return ""; // If the concatenations are not equal, there is no common divisor substring
            }
            if (str1.size() < str2.size()) {
                int result = gcd(str2.size(), str1.size());
                return str2.substr(0, result); 
            }
            else {
                int result = gcd(str1.size(), str2.size());
                return str1.substr(0, result); 
            };
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
