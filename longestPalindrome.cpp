#include <iostream>

//low can be same as i
//high can be same as i
//high can be same as low
//string can be empty
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int i = 1;
        int maxlen = 0;
        int newlen = 0;
        int len = s.size();
        // if (len == 1)
        //     return s;
        std::string new_string;
        if (s.empty())
            return "";
        while (s[i]) {
            int low = i - 1;
            int high = i + 1;
            while (low >= 0 && s[low] == s[i])
                low--;
            while (high <= len && s[high] == s[i])
                high++;
            while ((low >= 0 && high <= len) && (s[high] == s[low])) {
                low--;
                high++;
            }
            newlen = high - low - 1;
            if (newlen > maxlen) {
                maxlen = newlen;
                new_string = s.substr(low + 1, maxlen);
            }
            i++;
        }
        if (maxlen == 0)
            return new_string = s.substr(0, 1);
        return new_string;
    }
};

int main() {
    std::string input = "acb";
    Solution solution;
    std::string newString;

    newString = solution.longestPalindrome(input);
    std::cout << newString << std::endl;
    return 0;
}