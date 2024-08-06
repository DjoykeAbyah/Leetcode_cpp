#include <iostream>
#include <vector>

class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        int flowerbedSize = flowerbed.size();
        int maxFlowers = 0;

        for (int i = 0; i < flowerbedSize; ) {
            if (flowerbed[i] == 0) {

                bool prevEmpty = (i == 0) || (flowerbed[i - 1] == 0);
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