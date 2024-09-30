//
// Created by Ankit Sahu on 9/28/24.
//
#include<iostream>
#include<vector>

using namespace std;

//class Test {
//public:
//    vector<int> vec;
//
//    Test() {
//        vec.push_back(10);
//        vec.push_back(20);
//        vec.push_back(30);
//        vec.push_back(40);
//
//    }
//
//    void printVec() {
//        for (int &num: vec) {
//            cout << num << " ";
//        }
//    }
//};

class Solution {


public:

//    int memo[1000000][1000000000];
    int n;
    int rec(vector<int>& heights, int bricks, int ladders, int idx){
        if(idx == n-1) return 0;
//        if(memo[ladders][bricks] != -1) return memo[ladders][bricks];
        if(heights[idx] >= heights[idx+1]) {
            return 1 + rec(heights, bricks, ladders, idx+1);
        } else{
            int byLadders = 0, byBricks = 0;
            int diff = heights[idx+1] - heights[idx];

            if(diff <= bricks){
                byBricks = 1 + rec(heights, bricks-diff, ladders, idx+1);
            }
            if(ladders >0)
                byLadders = 1 + rec(heights, bricks, ladders-1, idx+1);

            return  max(byLadders, byBricks);
        }
    }

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        n = heights.size();
//        memset(memo, -1, sizeof(memo));
        return rec(heights, bricks, ladders, 0);
    }
};

int main() {
    Solution obj;
    int arr[] = {4,12,2,7,3,18,20,3,19};

    vector<int> heights;

    for(int i=0; i<9; i++){
        heights.emplace_back(arr[i]);
    }
    cout<<obj.furthestBuilding(heights, 10, 2);
    return 0;
}
