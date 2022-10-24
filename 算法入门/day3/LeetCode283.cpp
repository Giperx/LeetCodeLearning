//
// Created by Giperx on 2022/10/23.
//
#include <vector>
using namespace std;
// 移动零
class Solution {
public:
    //O(n)  O(1)    两次遍历，双指针，将非0元素从前往后依次放入，直到结束，再一次循环赋0
    void moveZeroes1(vector<int>& nums) {
        int i = 0, j = 0;
        for(;i < nums.size();i++){
            if(nums[i]) nums[j++] = nums[i];
        }

        while(j < nums.size()) nums[j++] = 0;
    }

    //O(n)  O(1)    单次遍历，双指针，依次交换边界非0元素
    void moveZeroes(vector<int>& nums){
        int i = 0, j = 0;
        for(; i < nums.size(); i ++){
            if(nums[i]) swap(nums[j++], nums[i]);
        }
    }
};