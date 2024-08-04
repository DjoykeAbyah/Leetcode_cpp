#include <iostream>
#include <vector>
#include <algorithm> // for std::max_element

class Solution {
public:
    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
        //determine max number in vector
        int max_num = *max_element(candies.begin(), candies.end());
        //create bool vector
        std::vector<bool> result;
        //loop through vector with range based for loop
        for (int candy : candies) {
            if ((candy + extraCandies) >= max_num)
                result.push_back(true);
            else
                result.push_back(false);
        }
        return result;
    }
};

int main() {
    Solution solution;
    std::vector<int> candies1 = {2, 3, 5, 1, 3};
    int extraCandies1 = 3;

    solution.kidsWithCandies(candies1, extraCandies1); // Output: "true true true false true "

    return 0;
}