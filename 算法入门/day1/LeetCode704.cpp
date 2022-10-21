//
// Created by Giperx on 2022/10/21.
//
// 二分查找
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //O(logn)   O(1)
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid = 0;
        while(l <= r){
            mid = l + r >> 1;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
};