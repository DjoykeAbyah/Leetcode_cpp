#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// check if number of occurences for each value is unique
//return true if yes
//return false if no
//maybe create map with as key the int of occurences and num of ocurrences
class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {

		std::unordered_map<int, int> incrementmap;
		for (int element : arr)
		{
			//adds it if not in map 
			//increments it if in map
			//accesses value associated with key
			incrementmap[element]++; //increment 
		}

		std::unordered_set<int> check;
		for (auto element : incrementmap) {
			if (check.insert(element.second).second == false) //2nd second accesses the bool value from the pair returned by insert.
				return false; //cant insert because already exists
		}
		return true;
    }
};

int main() {
	std::vector<int> arr = {1,2,2,1,1,3};
	Solution Solution;

	std::cout << std::boolalpha << Solution.uniqueOccurrences(arr) << std::endl;

	return 0;
}