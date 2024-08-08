#include <iostream>

// string containing other characters than palindrome
// single character is a palindrome.
// need to keep track of beginning and end.
// posibitliy of baab and not just bab uneven count palindorme and even count palindrome
// lowercase characters. no checks needed. no spaces.

// main opzetten
// iterator starting maybe at pos 1
// an iterator before one and iterator after one.
// check possibility of position left and iterator maybe palindrome same character 
// baab cbabc

bool palindrome(std::string s) {

    int left = 0;
    int right = s.size() - 1;

    while (left < right)
    {
        if (s[left] == s[right]) {
            left++;
            right--;
        }
        else 
            return false;
    }
    return true;
}


int main() {
    std::string word = "dbabe";

    std::cout << std::boolalpha << palindrome(word) << std::endl;
    return 0;
}