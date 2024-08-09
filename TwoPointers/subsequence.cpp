#include <iostream>
#include <string>


// see if string one is subsequence
//need to be the same order of characters
//does it mean that its interchanged 

// checking 2 strings agains eachother
//find? maybe

//need to know lenght of s to know how many elements
// need to see if t is longer than s
class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        if (t.empty() && s.empty())
            return true;
        if (t.size() <= s.size())
            return false;
        int size = t.size();
        int count = s.size();
        int i = 0;
        for (int j = 0; j < size; j++) {
            if (s[i] == t[j] && count != 0) {
                i++;
                count--;
            }
        }
        if (count != 0)
            return false;
        return true;
    }
};

int main() {
    // std::string s = "abc";
    // std::string t = "ahbgdc";
    // std::string s = "axc";
    // std::string t = "ahbgdc";
    std::string s = "";
    std::string t = "";
    Solution solution;

    std::cout << std::boolalpha << solution.isSubsequence(s, t);

    return 0;
}