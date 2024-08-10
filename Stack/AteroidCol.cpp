#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>


//positive number is moving right
//negative is moving left
//if bigger and smaller number collide smaller disappears
//if even numbers collide both disappear
//keep comparing until everything is compared

//it's a stack question so how to solve it with stack?

//create stack
//loop and put all positive numbers on stack
//if negative number arrives compare to top of stack

//if even pop the top
//if uneven continue the loop

//return same vector? or maybe perform on string?
class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::stack<int> stack;
		for (int asteroid : asteroids) {
			while (!stack.empty() && asteroid < 0 && stack.top() > 0) {
				if (stack.top() < abs(asteroid)) {
					stack.pop();//top asteroid explodes
					continue;//continue checking
				}
				else if (stack.top() == abs(asteroid)) {
					stack.pop();//both explode
				}
				// If the current asteroid is smaller, it gets destroyed
				asteroid = 0; // Mark the asteroid as destroyed
				break;
			}
			if (asteroid != 0)
				stack.push(asteroid);
		}
		
		asteroids.clear();
		while (!stack.empty()) {
			asteroids.push_back(stack.top());
			stack.pop();
		}
		std::reverse(asteroids.begin(), asteroids.end());
		return asteroids;
    }
};

int main() {
	// std::vector<int> vec = {5, 10, -5};
	// std::vector<int> vec = {8, -8};
	// std::vector<int> vec = {10, 2, -5};
	std::vector<int> vec ={-2,-1,1,2};
	Solution solution;
	solution.asteroidCollision(vec);

	for (int element : vec) 
		std::cout << element << std::endl;
	return 0;
}

