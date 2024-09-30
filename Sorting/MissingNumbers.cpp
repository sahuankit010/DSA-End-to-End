//
// Created by Ankit Sahu on 9/24/24.
//
#include "/Users/sahuankit010/Desktop/Repo/DSA-End-to-End/Initialize.h"
#include "/Users/sahuankit010/Desktop/Repo/DSA-End-to-End/Print.h"
#include <iostream>
#include <vector>
using namespace std;
std::vector<int> findMissingNumbers(std::vector<int>& nums) {
    int i = 0;
    while (i < nums.size()) {
        int correctIndex = nums[i] - 1;
        if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[correctIndex]) {
            std::swap(nums[i], nums[correctIndex]);
        } else {
            ++i;
        }
    }

    std::vector<int> missingNumbers;
    for (int j = 0; j < nums.size(); ++j) {
        if (nums[j] != j + 1) {
            missingNumbers.push_back(j + 1);
        }
    }
    return missingNumbers;
}

int main() {
    int arr[] = {4, 3, 2, 7, 8, 2, 3, 1};
    Initialize initializeObj;
    Print printObj;
    vector<int> nums = initializeObj.initializeVector(arr, 8);
    vector<int> missingNumbers = findMissingNumbers(nums);
    printObj.print(nums);
    std::cout << "Missing numbers: ";
    printObj.print(missingNumbers);

    return 0;
}
