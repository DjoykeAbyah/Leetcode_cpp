#include <iostream>
#include <vector>
#include <algorithm>

#include <iostream>
#include <vector>

class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        int flowerbedSize = flowerbed.size();
        int maxFlowers = 0;

        for (int i = 0; i < flowerbedSize; ) {
            if (flowerbed[i] == 0) {
                /**
                * This condition checks if the current position i is the first position in the flowerbed. 
                * If i is 0, there is no previous position to check
                * The second condition checks if the previous position is empty. This is relevant when i is not the first position.
                */
                bool prevEmpty = (i == 0) || (flowerbed[i - 1] == 0);
                /** 
                * This condition checks if the current position i is the last position in the flowerbed. If i is the last position, there is no next position to check,
                * This condition checks if the next position is empty. This is relevant when i is not the last position.
                */
                bool nextEmpty = (i == flowerbedSize - 1) || (flowerbed[i + 1] == 0);

                if (prevEmpty && nextEmpty) {
                    // Plant a flower here
                    flowerbed[i] = 1;
                    maxFlowers++;
                    if (maxFlowers >= n) {
                        return true;
                    }
                    // Skip the next spot, ensuring that we do not attempt to plant a flower in an adjacent spot
                    i += 2;
                } 
                else {
                    // Move to the next spot
                    i++;
                }
            } 
            else {
                // Move to the next possible spot, ensuring that we do not attempt to plant a flower in an adjacent spot
                i += 2;
            }
        }
        return maxFlowers >= n;
    }
};

int main() {
	std::vector<int> flowerbed = {1, 0, 1, 0, 1};
	std::vector<int> flowerbed1 = {0, 1, 0};
	std::vector<int> flowerbed2 = {1, 0, 1};
	std::vector<int> flowerbed3 = {1, 0, 0, 0, 1};
	std::vector<int> flowerbed4 = {1, 0, 0, 0, 1};
	std::vector<int> flowerbed5 = {0, 0, 1, 0, 1};
	Solution solution;
	bool result;

	result = solution.canPlaceFlowers(flowerbed, 1);
	std::cout << std::boolalpha << result << std::endl;

	result = solution.canPlaceFlowers(flowerbed1, 1);
	std::cout << std::boolalpha << result << std::endl;

	result = solution.canPlaceFlowers(flowerbed2, 1);
	std::cout << std::boolalpha << result << std::endl;

	result = solution.canPlaceFlowers(flowerbed3, 1);
	std::cout << std::boolalpha << result << std::endl;

	result = solution.canPlaceFlowers(flowerbed4, 2);
	std::cout << std::boolalpha << result << std::endl;
	return 0;
}


/**
 * This condition checks if the current position i is the first position in the flowerbed. 
 * If i is 0, there is no previous position to check
 * The second condition checks if the previous position is empty. This is relevant when i is not the first position.
 */

/** 
 * This condition checks if the current position i is the last position in the flowerbed. If i is the last position, there is no next position to check,
 * This condition checks if the next position is empty. This is relevant when i is not the last position.
*/