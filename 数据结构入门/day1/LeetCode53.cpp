//
// Created by Giperx on 2022/9/8.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution { // 最大子数组和
public:
    //O(n)  一维dp
    int maxSubArray(vector<int> nums){
        int res = 0, tmp = 0;
        tmp = nums[0];
        res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if ((tmp + nums[i]) >= nums[i]) tmp += nums[i];
            else tmp = nums[i];

            res = max(res, tmp);
        }
        return res;
    }
};