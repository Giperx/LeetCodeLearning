//
// Created by Giperx on 2022/10/29.
//
#include <queue>
using namespace std;
// 01矩阵
class Solution {
private:
    int xs[4] = {-1, 0, 1, 0}, ys[4] = {0, 1, 0, -1};
public:
    //O(m*n)  O(m*n)    bfs
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist (m, vector<int>(n));
        vector<vector<int>> seen (m, vector<int>(n));
        queue<pair<int, int>> q;
        for(int i = 0; i < mat.size(); i ++)
            for(int j = 0; j < mat[0].size(); j ++)
                if(!mat[i][j]) q.emplace(i, j), seen[i][j] = 1;

        while(!q.empty()){
            auto[x, y] = q.front();
            q.pop();
            for(int i = 0; i < 4; i ++){
                int nx = x + xs[i], ny = y + ys[i];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && !seen[nx][ny]){
                    dist[nx][ny] = dist[x][y] + 1;
                    seen[nx][ny] = 1;
                    q.emplace(nx, ny);
                }
            }
        }

        return dist;
    }

};