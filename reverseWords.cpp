#include <iostream>
#include <string>
#include <algorithm>


class Solution {
public:
    std::string reverseWords(std::string s) {
        //reverse the entire string
        reverse(s.begin(), s.end());
        int size = s.size();
        int right = 0;
        int i = 0;
        while (i < size) {
            //skip over the spaces.
            while (i < size && s[i] == ' ')
                i++;
            //leave method when end of string encountered
            if (i == size)
                break ;
            if (right != 0 && right != size) {
                s[right] = ' ';
                right++;
            }
            //take out extra spaces
            int word_start = right;
            while (i < size && s[i] != ' ') {
                s[right] = s[i];
                right++;
                i++;
            }
            reverse(s.begin() + word_start, s.begin() + right);
        }
        s.resize(right);
        return s;
    }
};

int main() {
    std::string word = "hello banana  ";
    std::string new_string;
    Solution solution;

    new_string = solution.reverseWords(word);
    std::cout << new_string;
    return 0;
}