//
// Created by Giperx on 2022/11/15.
//
#include <vector>
using namespace std;
// 三角形最小路径和
class Solution {
public:
    //O(n*2) O(n) dp
    //f(i, j) = min(f(i - 1, j), f(i - 1, j - 1)) + triangle(i, j))
    //f(i, j) = min(f(j), f(j - 1)) + triangle(i, j)    空间优化
    int minimumTotal(vector<vector<int>>& triangle) {
        if(!triangle.size()) return 0;
        int n = triangle.size();
        // vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> dp(n, 0);
        // dp[0][0] = triangle[0][0];
        dp[0] = triangle[0][0];

        for(int i = 1; i < n; i ++)
            // for(int j = 0; j <= i; j ++){
            for(int j = i; j >= 0; j --){
                if(j == 0){
                    // dp[i][j] = dp[i - 1][j] + triangle[i][j];
                    dp[j] = dp[j] + triangle[i][j];
                }
                else if(j == i){
                    // dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                    dp[j] = dp[j - 1] + triangle[i][j];
                }
                else{
                    // dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
                    dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
                }
            }
        int res = 2100000;
        // for(auto  &x:dp[n - 1]) res = min(res, x);
        for(auto  &x:dp) res = min(res, x);
        return res;
    }

};