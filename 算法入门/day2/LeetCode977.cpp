//
// Created by Giperx on 2022/10/22.
//
#include <iostream>
#include <vector>
using namespace std;
// 有序数组的平方
class Solution {
public:
    //O(n) O(n) 双指针
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto &x:nums)  x = x * x;

        vector<int> res(nums.size());
        int pot = nums.size() - 1;
        for(int i = 0, j = nums.size() - 1; i <= j;){
            if(nums[i] >= nums[j]) res[pot--] = nums[i++];
            else res[pot--] = nums[j--];
        }

        return res;
    }
};