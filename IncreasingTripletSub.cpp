#include <vector>
#include <iostream>

class Solution {
public:
    bool increasingTriplet(std::vector<int>& nums) {
       int size = nums.size();

       if (size < 3)
            return false;

       int first = INT_MAX;
       int second = INT_MAX;

       for (int i = 0; i < size; i++) {
            if (nums[i] <= first)
                first = nums[i];
            else if (nums[i] <= second)
                second = nums[i];
            else
                return true;
       }
       return false;
    }
};

int main() {
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::vector<int> nums2 = {5, 4, 3, 2, 1};
    std::vector<int> nums3 = {2, 1, 5, 0, 4, 6};

    Solution solution;

    std::cout << std::boolalpha << solution.increasingTriplet(nums1) << std::endl;
    std::cout << std::boolalpha << solution.increasingTriplet(nums2) << std::endl;
    std::cout << std::boolalpha << solution.increasingTriplet(nums3) << std::endl;
}