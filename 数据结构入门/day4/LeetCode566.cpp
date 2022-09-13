//
// Created by Giperx on 2022/9/13.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
//重塑矩阵
class Solution {
public:
    // O(rc)    模拟
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int ro = mat.size(), col = mat[0].size(); // 行、列
        int sz = ro * col; //mat元素总个数
        if (sz != r * c) return mat;
        vector<vector<int>> res(r, vector<int>(c));
        int cnt = 0; //计数
        for(int i = 0; i < r; i ++){
            for(int j = 0; j < c; j ++){
                res[i][j] = mat[cnt / col][cnt % col];
                cnt++;
            }
        }
        return res;
    }
};
