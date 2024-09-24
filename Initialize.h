//
// Created by Ankit Sahu on 9/24/24.
//

#ifndef DSA_END_TO_END_INITIALIZE_H
#define DSA_END_TO_END_INITIALIZE_H

#include<iostream>
#include<vector>

using namespace  std;
class Initialize {

public:
    vector<int> initializeVector(int arr[], int n){
        vector<int> nums;

        for(int i=0; i<n; i++){
            nums.push_back(arr[i]);
        }

        return nums;
    }
};


#endif //DSA_END_TO_END_INITIALIZE_H
