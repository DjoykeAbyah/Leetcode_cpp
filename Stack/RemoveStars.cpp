#include <iostream>
#include <stack>
#include <algorithm>

class Solution {
public:
    std::string removeStars(std::string s) {
		std::stack<char> stack;
		int size = s.size();

		for (int i = 0; i < size; i++) {
			if (s[i] != '*') 
				stack.push(s[i]);
			else
				stack.pop();
		}
		s.clear();

		while(!stack.empty())
		{
			s.push_back(stack.top());
			stack.pop();
		}
		std::reverse(s.begin(), s.end());
		return s;
    }
};

int main() {
	std::string s = "leet**cod*e";
	std::string newString;
	Solution solution;

	newString = solution.removeStars(s);
	std::cout << newString << std::endl;
	return 0; 
}