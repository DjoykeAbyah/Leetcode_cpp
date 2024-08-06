#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> leftside(n, 1);
        std::vector<int> rightside(n, 1);
        std::vector<int> result(n);

        for (int i = 1; i < n; i++) {
            leftside[i] = leftside[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            rightside[i] = rightside[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; i++) {
            result[i] = rightside[i] * leftside[i];
        }
        return result;
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> results;
    Solution solution;

    results = solution.productExceptSelf(nums);

    for (int result : results) {
        std::cout << result << std::endl;
    }
    return 0;
}