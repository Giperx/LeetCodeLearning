//
// Created by Giperx on 2022/10/29.
//
// 腐烂的橘子
#include <queue>
using namespace std;
class Solution {
public:
    // O(m*n)  O(m*n) bfs 洪泛
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> seen (m, vector<int>(n));
        queue<pair<int, int>> q;
        int cnt = 0, res = 0, cnt0 = 0, cnt2 = 0;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(grid[i][j] == 2) q.emplace(i, j), cnt2++;
                if(grid[i][j] == 0) cnt0++;
            }
        }
        if(cnt0 + cnt2 == m * n) return 0; //特判全是烂橘子

        int xs[4] = {-1, 0, 1, 0}, ys[4] = {0, 1, 0, -1};
        while(!q.empty()){
            cnt = q.size();
            while(cnt--){
                auto [x, y] = q.front();
                q.pop();
                for(int i = 0; i < 4; i ++){
                    int nx = x + xs[i], ny = y + ys[i];
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.emplace(nx, ny);
                    }
                }
            }
            res++;
        }
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                if(grid[i][j] == 1) return -1;//特判有橘子不会腐烂
        return res - 1;
    }
};