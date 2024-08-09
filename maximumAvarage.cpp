#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        int currentSum = 0;

        for (int i = 0; i < k; i++) {
            currentSum = currentSum + nums[i];
        }

        int maxSum = currentSum;
        int size = nums.size();

        for (int i = k; i < size; i++) {
            //nums[i] is number entering the sum and nums[i - k] is number leaving the sum
            currentSum = currentSum + nums[i] - nums[i - k];
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
        return static_cast<double>(maxSum) / k;
    }
};

int main() {
    Solution solution;
    std::vector<int> numbers = {1, 12, -5, -6, 50, 3};
    int k = 4;
    double result = solution.findMaxAverage(numbers, k);
    std::cout << "Maximum average is: " << result << std::endl;
}

