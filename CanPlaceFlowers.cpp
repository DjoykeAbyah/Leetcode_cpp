#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        int flowerbedSize = flowerbed.size();
        // int amountFlowerbeds = std::count(flowerbed.begin(), flowerbed.end(), 1);
		int maxFlowers;

		for (int i = 0; i < flowerbedSize; i++) {
			if (flowerbed[i] == 0) {
				
			}
		}

        // if (flowerbedSize % 2 != 0) {
        //     maxFlowers = (flowerbedSize + 1) / 2;
		// }
        // else {
        //     maxFlowers = flowerbedSize / 2;
        // }
		
		// //check for available spots
		// int availableSpots = maxFlowers - amountFlowerbeds;

		// if (n <= availableSpots)
		// 	return true;
		// else
		// 	return false;
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