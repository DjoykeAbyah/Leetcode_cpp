#include <iostream>
#include <vector>
#include <unordered_set>


//make sets out of the vectors because arent key value pairs
//loop through both vectors and check if at num it's present in the other vector

class Solution {
public:
    std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        std::unordered_set<int> set2(nums2.begin(), nums2.end());

        //unordered set find method only needs the key
        //find numbers in nums1 that arent in nums2
        // Remove elements from set1 that are found in set2
        for (int num : nums2) {
            set1.erase(num);  // Removes num from set1 if it exists
        }


        //find numbers in nums2 that arent in nums1
       // Remove elements from set1 that are found in set2
        for (int num : nums1) {
            set2.erase(num);  // Removes num from set1 if it exists
        }

        // Convert unordered_set to vector and return as a vector of vectors
        std::vector<int> vec1(set1.begin(), set1.end());
        std::vector<int> vec2(set2.begin(), set2.end());

        // Step 4: Return the result as a vector of vector
        return {vec1, vec2};
    }

    std::vector<std::vector<int>> findDifference2(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        std::unordered_set<int> set2(nums2.begin(), nums2.end());

        for (int num : nums2) {
            set1.erase(num);  // Removes num from set1 if it exists
        }

        for (int num : nums1) {
            set2.erase(num);  // Removes num from set1 if it exists
        }

        return {std::vector<int>(set1.begin(), set1.end()), std::vector<int>(set2.begin(), set2.end())};
    }
};



int main() {
    std::vector<int> nums1 = {1,2,3};
    std::vector<int> nums2 = {2,4,6};

    Solution solution;

    //vector of vectors
    std::vector<std::vector<int>> results = solution.findDifference(nums1, nums2);

    std::cout << "elements in num1 but not in num2" << std::endl;
    for (int num : results[0])
        std::cout << num << std::endl;

    std::cout << "elements in num2 but not in num1" << std::endl;
    for (int num : results[1])
        std::cout << num << std::endl;
}