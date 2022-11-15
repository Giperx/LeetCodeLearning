//
// Created by Giperx on 2022/11/15.
//
#include <vector>
using namespace std;
// 太平洋大西洋水流问题
class Solution {
public:
    // O(m * n) O(m * n)    dfs 反向从海边往内陆判断陆地，改变状态数组
    int xs[4] = {-1, 0, 1, 0}, ys[4] = {0, 1, 0, -1};
    vector<vector<int>> heights;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> post(m, vector<int>(n, false));
        vector<vector<int>> aost(m, vector<int>(n, false));

        for(int i = 1; i < n; i ++) dfs(0, i, post);
        for(int i = 0; i < n; i ++) dfs(m - 1, i, aost);
        for(int i = 0; i < m; i ++) dfs(i, 0, post);
        for(int i = 0; i < m - 1; i ++) dfs(i, n - 1, aost);

        vector<vector<int>> res;
        vector<int> tmp(2, -1);
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++){
                if(aost[i][j] && post[i][j]){
                    tmp[0] = i, tmp[1] = j;
                    res.emplace_back(tmp);
                }
            }
        return res;
    }

    void dfs(int i, int j, vector<vector<int>>& oceans){
        if(oceans[i][j]) return;

        int m = oceans.size(), n = oceans[0].size();
        oceans[i][j] = true;
        for(int k = 0; k < 4; k ++){
            int x = i + xs[k], y = j + ys[k];
            if(x >= 0 && x < m && y >= 0 && y < n && heights[x][y] >= heights[i][j])
                dfs(x, y, oceans);
        }
    }
};