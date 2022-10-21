//
// Created by Giperx on 2022/10/21.
//
//搜索插入位置
#include <vector>
using namespace std;
class Solution {
public:
    //O(logn)   O(1)
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), mid = 0;
        while(l < r){
            mid = l + r >> 1;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
