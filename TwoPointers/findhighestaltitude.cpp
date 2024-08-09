#include <iostream>
#include <vector>

//declare max int
//need to have a start position 0 to calulate the first element with 
//in for loop maybe if statement if i = 0 to calculate i + 1 with that.
//not sure if thats the entire algortihm 

// want to safe result with the maxnum
//replace maxnum with result if higher

//return result

class Solution {
public:
    int largestAltitude(std::vector<int>& gain) {
        int maxNum = INT_MIN;
        int size = gain.size();
        int result;
        for (int i = 0; i < size; i++) {

            if (i == 0) {
                gain[i] = gain[i] + 0;
                result = gain[i];
            }
            else if (i != 0) {
                gain[i] = gain[i] + gain[i - 1];
                result = gain[i];
            }
            if (maxNum < result)
                maxNum = result;
        }
        if (maxNum < 0)
            return 0;
        return (maxNum);
    }
};

int main() {
    Solution solution;
    // std::vector<int> altitudes = {-5, 1, 5, 0, -7};
    std::vector<int> altitudes = {-4,-3,-2,-1,4,3,2};
    int result = solution.largestAltitude(altitudes);

    std::cout << "final result: " << result << std::endl;
    return 0;

}