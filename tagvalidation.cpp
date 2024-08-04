#include <iostream>
#include <string>
#include <stack>

bool isValidTagname(const std::string &tagName) {
    //tagname can not be empty or larger than 9 characters
    if (tagName.empty() || tagName.size() > 9)
        return false;
    //tagname needs to include alphabetical characters
    for (size_t i = 0; i < tagName.size(); ++i) {
        if (tagName[i] < 'A' || tagName[i] > 'Z')
            return false;
    }
    return true;
}

class Solution {
public:
    bool isValid(std::string code) {

        std::stack<std::string> tags;
        size_t i = 0;
        bool hasRoot = false;

        while (i < code.size()) {

            if (code.substr(i, 9) == "<![CDATA[") {
                // Handle CDATA and skip over
                if (!hasRoot)
                    return false;
                size_t j = i + 9;
                i = code.find("]]>", j);
                if (i == std::string::npos)
                    return false;
                i = i + 3;
            } 
            else if (code.substr(i, 2) == "</") {
                // Handle closing tag
                size_t j = i + 2;
                i = code.find(">", j);
                if (i == std::string::npos)
                    return false;
                std::string tagName = code.substr(j, i - j);
                if (tags.empty() || tags.top() != tagName)
                    return false;
                tags.pop();
                i = i + 1;
                // Ensure no extra content after the root tag is closed
                if (tags.empty() && i != code.size())
                    return false;
            } 
            else if (code.substr(i, 1) == "<") {
                // Handle opening tag
                size_t j = i + 1;
                i = code.find(">", j);
                if (i == std::string::npos)
                    return false;
                std::string tagName = code.substr(j, i - j);
                //check if tagname is valid
                if (!isValidTagname(tagName))
                    return false;
                tags.push(tagName);
                // boolean to check if there is an opening tag
                if (!hasRoot) {
                    hasRoot = true;
                }
                i = i + 1;
            } 
            else {
                // Handle regular text
                if (tags.empty())
                    return false;
                i++;
            }
        }
        return tags.empty() && hasRoot; // Ensure all tags are properly closed
    }
};

int main() {
    std::string code1 = "<DIV>This is the first line <![CDATA[<div>]]></DIV>";
    std::string code2 = "<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>";
    std::string code3 = "<A>  <B> </A>   </B>";
    std::string code4 = "<TRUE><![CDATA[wahaha]]]><![CDATA[]> wahaha]]></TRUE>";
    std::string code5 = "<![CDATA[wahaha]]]><![CDATA[]> wahaha]]>"; // Should return false

    Solution solution;
    
    std::cout << (solution.isValid(code1) ? "true" : "false") << std::endl; // Output: true
    std::cout << (solution.isValid(code2) ? "true" : "false") << std::endl; // Output: true
    std::cout << (solution.isValid(code3) ? "true" : "false") << std::endl; // Output: false
    std::cout << (solution.isValid(code4) ? "true" : "false") << std::endl; // Output: true
    std::cout << (solution.isValid(code5) ? "true" : "false") << std::endl; // Output: false
    
    return 0;
}
