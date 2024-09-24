//
// Created by Ankit Sahu on 9/24/24.
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
