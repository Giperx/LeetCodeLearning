//
// Created by Giperx on 2022/11/7.
//
#include <vector>
using namespace std;
// 全排列
class Solution {
private:
    vector<vector<int>> res;
    bool *sta = new bool[10](); // 状态数组
    vector<int> trace; // 路径
public:
    // O(n*n!)  O(n)    递归
    void dfs(vector<int> &nums, int cnt){
        if(cnt == nums.size()){
            res.emplace_back(trace);
            return;
        }
        for(int i = 0; i < nums.size(); i ++){
            if(!sta[i])
            {
                trace.emplace_back(nums[i]);
                sta[i] = true;
                dfs(nums, cnt + 1);
                sta[i] = false;
                trace.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
};