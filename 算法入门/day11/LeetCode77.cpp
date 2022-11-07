//
// Created by Giperx on 2022/11/7.
//
#include <vector>
using namespace std;
// 组合
class Solution {
private:
    vector<vector<int>> res;
    vector<int> trace;
public:
    //O((n k) * k)  O(n)    递归实现组合型枚举Cnk
    void dfs(int n, int k, int cur){
        if(n - cur + 1 < k - trace.size()) return;
        if(trace.size() == k) {
            res.push_back(trace);
            return;
        }

        trace.push_back(cur);
        dfs(n, k, cur + 1);
        trace.pop_back();
        dfs(n, k, cur + 1);

    }
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return res;
    }
};