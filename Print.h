//
// Created by Ankit Sahu on 9/24/24.
//

#ifndef DSA_END_TO_END_PRINT_H
#define DSA_END_TO_END_PRINT_H
#include<iostream>
#include<vector>

using namespace  std;

class Print {
public:
    void print(vector<int> &nums){

        for(int i=0; i<nums.size(); i++){
            cout<<nums[i]<< " ";
        }

        cout<<endl;
    }
};


#endif //DSA_END_TO_END_PRINT_H
