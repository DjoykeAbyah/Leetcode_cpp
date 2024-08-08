#include <vector>
#include <iostream>

class Solution {
public:
    int compress(std::vector<char>& chars) {
        int size = chars.size();
        int write = 0;
        for (int i = 0; i < size;) {
            char currentchar = chars[i];
            int count = 0;

            //count occurences of the current character
            while (i < size && chars[i] == currentchar) {
                i++;
                count++;
            }
            // write characters
            chars[write] = currentchar;
            write++;

            //write the count if greater than 1
            if (count > 1) {
                std::string countStr = std::to_string(count);
                for (char c : countStr) {
                    chars[write] = c;
                    write++;
                }
            }  
        }
        return write; 
    }
};

int main() {
    std::vector<char> charvector = {'a','a','b','b','c','c','c'};
    // std::vector<char> charvector = {'a','a'};
    Solution solution;
    
    int result = solution.compress(charvector);
    std::cout << "result = " << result << std::endl;
    for (char chars : charvector) {
        std::cout << chars << std::endl;
    }
}