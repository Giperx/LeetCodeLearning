//
// Created by Giperx on 2022/9/10.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//两数之和
class Solution{
public:
    //O(N^2)    暴力
    vector<int> twoSum(vector<int>& nums, int target){
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
    }

    //O(N)  哈希表
    vector<int> twoSum1(vector<int>& nums, int target){
        unordered_map<int, int>hash_map;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hash_map.find(target - nums[i]);
            if (it != hash_map.end()) return {it->second, i};
            hash_map[nums[i]] = i;
        }
        return {};
    }
};
