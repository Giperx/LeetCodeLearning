//
// Created by Giperx on 2022/11/23.
//
#include <iostream>
#include <vector>
using namespace std;
// 只出现一次的数字
class Solution {
public:
    // O(n) O(1)    异或^
    // 异或满足 交换律  a ^ b ^ a = a ^ a ^ b = b
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1; i < nums.size(); i ++){
            res = res ^ nums[i];
        }
        return res;
    }
};