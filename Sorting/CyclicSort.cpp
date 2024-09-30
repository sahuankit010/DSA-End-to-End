//
// Created by Ankit Sahu on 9/24/24.
//Time Complexity: O(n), where n is the number of elements in the array.
//Space Complexity: O(1), sorts the array in-place.
//
#include "/Users/sahuankit010/Desktop/Repo/DSA-End-to-End/Initialize.h"
#include "/Users/sahuankit010/Desktop/Repo/DSA-End-to-End/Print.h"
#include<iostream>
//#include<bits/stdc++.h>

#include <vector>
using namespace std;

void cyclic_sort(vector<int> &nums){
    cout<<"In Cyclic Sort Function\n";
    int n = nums.size();

    int i = 0;

    while(i<n){
        int correctIndex = nums[i]-1;

        if(nums[i] != nums[correctIndex]){
            swap(nums[i], nums[correctIndex]);
        } else {
            i++;
        }
    }
}


int main(){
    cout<<"Hello World\n";
    Initialize initializeObj;
    Print printObj;
    int arr[] = {5, 3, 1, 4, 2};
    vector<int> nums = initializeObj.initializeVector(arr, 5);
    printObj.print(nums);
    cyclic_sort(nums);
    printObj.print(nums);


    return 0;
}
/*
 * When to Use Cyclic Sort
Cyclic Sort is particularly useful when dealing with:

Finding missing numbers in a sequence.
Detecting duplicates in an array.
Restoring corrupted sequences where elements are shuffled within a known range.
Advantages
Time Efficiency: Runs in O(n) time, making it highly efficient for large datasets.
Space Efficiency: Sorts the array in-place, requiring O(1) additional space.
Limitations
Range Constraint: Only works efficiently when numbers are in a known range from 1 to n.
Negative Numbers and Zeros: The algorithm needs modification to handle arrays containing zeros or negative numbers.
Conclusion
Cyclic Sort is a powerful algorithm for specific use cases involving arrays of consecutive integers within a known range
 . Its in-place sorting and linear time complexity make it an optimal choice for problems that fit its application criteria.
Cyclic Sort is an efficient sorting algorithm specifically designed for scenarios where you have an array of n integers
 ranging from 1 to n, and the array may contain duplicates or be missing some numbers. The key characteristic of this
 algorithm is that it sorts the array in-place with a time complexity of O(n).

How Cyclic Sort Works
The main idea behind Cyclic Sort is to place each number at its correct index. Since the numbers are in the range 1 to n,
 each number should ideally be at index number - 1. The algorithm iterates through the array, and for each element:

Check if the current element is at its correct position.
If it is, move to the next element.
If not, swap the current element with the element at its correct position.
Continue this process until the current element is at its correct position.
Steps of Cyclic Sort
Initialize a variable i = 0.
While i < n, do the following:
Calculate the correct index for the current element: correctIndex = nums[i] - 1.
If nums[i] is not at the correct index, swap nums[i] with nums[correctIndex].
Else, increment i by 1.
Example
Consider the array: [3, 1, 5, 4, 2]

Iteration 1 (i = 0):
nums[0] = 3, correct index is 2.
Swap nums[0] and nums[2]: [5, 1, 3, 4, 2].
Iteration 1 (after swap, nums[0] = 5):
nums[0] = 5, correct index is 4.
Swap nums[0] and nums[4]: [2, 1, 3, 4, 5].
Iteration 1 (after swap, nums[0] = 2):
nums[0] = 2, correct index is 1.
Swap nums[0] and nums[1]: [1, 2, 3, 4, 5].
Iteration 1 (after swap, nums[0] = 1):
Now, nums[0] is at the correct index.
Increment i to 1 and continue the process.
 */