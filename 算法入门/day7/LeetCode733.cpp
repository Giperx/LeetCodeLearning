//
// Created by Giperx on 2022/10/27.
//
#include <vector>
using namespace std;
// 图像渲染
class Solution {
private:
    int xs[4] = {-1, 0, 1, 0}, ys[4] = {0, 1, 0, -1};
public:
    // O(m*n)   O(m*n)  dfs 洪泛
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int src){
        if(image[sr][sc] != src) return;

        image[sr][sc] = color;
        for(int i = 0; i < 4; i ++){
            if(sr + xs[i] >= 0 && sr + xs[i] < image.size() && sc + ys[i] >= 0 && sc + ys[i] < image[0].size()){
                dfs(image, sr + xs[i], sc + ys[i], color, src);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        if(image[sr][sc] != color){
            dfs(image, sr, sc, color, image[sr][sc]);
        }
        return image;
    }
};