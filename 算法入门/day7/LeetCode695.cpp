//
// Created by Giperx on 2022/10/27.
//
#include <vector>
using namespace std;
// 岛屿的最大面积
class Solution {
private:
    int xs[4] = {-1, 0, 1, 0}, ys[4] = {0, 1, 0, -1};
    int dfs(vector<vector<int>>& grid, int a, int b){
        if(a < 0 || b < 0 || a >= grid.size() || b >= grid[0].size() || grid[a][b] != 1)
            return 0;
        grid[a][b] = 0;
        int res = 1;
        for(int i = 0; i < 4; i ++){
            res += dfs(grid, a + xs[i], b + ys[i]);
        }
        return res;
    }
public:
    // O(m*n)  O(m*n) dfs，洪泛法
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i ++)
            for(int j = 0; j < grid[0].size(); j ++)
                res = max(res, dfs(grid, i, j));
        return res;
    }
};