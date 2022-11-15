//
// Created by Giperx on 2022/11/13.
//
#include <vector>
using namespace std;
// 打家劫舍
class Solution {
public:
    // O(n)  O(1) dp
    // f(n) = max{f(n - 1), f(n - 2) + nums[n - 1]}
    int rob(vector<int>& nums) {
        if(!nums.size()) return 0;
        if(nums.size() == 1) return nums[0];

        // int dp[110]{};
        // dp[1] = nums[0];
        for (int i = 0; i < n; ++i) {
            
        }
        int a = 0, b = 0, c = nums[0];
        for(int i = 2; i <= nums.size(); i ++){
            // dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
            a = b, b = c;
            c = max(b, a + nums[i - 1]);
        }
        return c;
    }
};