#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int size = nums.size();
        int i = 0;
        for (int j = 0; j < size; j++) {
            if (nums[j] != 0) {
                std::swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};

int main() {
    std::vector<int> numbers = {0,1,0,3,12};
    Solution solution;

    solution.moveZeroes(numbers);
    for (int number : numbers) {
        std::cout << number << std::endl;
    }
}