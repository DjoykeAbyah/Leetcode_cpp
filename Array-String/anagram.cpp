#include <iostream>
#include <string>

// how often does a character occur, need to count/keep track. maybe with int?

// comparing 2 words
// lenght of both words need to be checked
// save characters in a string or maybe vector to compare to second string
// don't know yet how to compare to vector/string for loop? is there method maybe find?
// return bools.

// do I want a int character pair?
// or just int size len and when the character is found in word2 --. if int != 0 at the end return false?
bool anagram(std::string word1, std::string word2) {
    sort(word1.begin(), word1.end());
    sort(word2.begin(), word2.end());

    return word1 == word2;
}

int main() {
    std::string word1 = "race";
    std::string word2 = "care";

    std::cout << std::boolalpha << anagram(word1, word2);
    return 0;
}