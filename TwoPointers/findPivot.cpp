#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

//init int left
//init int right
//for loop vector
// as we loop calculate left from i and right ftom i

//can I prevent looping through the entire string all 
//the time to calculate left and right elements

// can I use a method?
//check wether left and right are equal and return index i


class Solution {
   public:
    int pivotIndex(std::vector<int>& nums) { 
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            if (leftSum == totalSum - leftSum - nums[i])
                return i;
            leftSum = leftSum + nums[i];
        }
        return -1;
    }

};

//slower version
// class Solution {
// public:
//     int pivotIndex(std::vector<int>& nums) {
//         int size = nums.size();
//         for (int i = 0; i < size; i++) {
            
//             int right = std::accumulate(nums.begin() + i + 1, nums.end(), 0);
//             int left = std::accumulate(nums.begin(), nums.begin() + i, 0);

//             if (left == right) {
//                 return i;
//             }
//         }
//         return - 1;
//     }
// };

int main() {
    Solution solution;
    std::vector<int> numbers = {1, 7, 3, 6, 5, 6};

    int output = solution.pivotIndex(numbers);
    std::cout << output << std::endl;
    return 0;
}