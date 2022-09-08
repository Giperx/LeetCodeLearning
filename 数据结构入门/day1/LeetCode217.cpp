//
// Created by Giperx on 2022/9/8.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {    // 存在重复元素
public:
    // Nlog(N)   排序+遍历
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i ++){
            if (nums[i] == nums[i - 1]) return true;
        }
        return false;
    }
    bool containsDuplicate1(vector<int>& nums) {
        // N    hash表判断
        unordered_set<int> maptmp;
        for(int t: maptmp){
            if (maptmp.find(t) != maptmp.end()) return true;
            maptmp.insert(t);
        }
        return false;
    }
};
