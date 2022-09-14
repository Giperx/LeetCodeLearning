//
// Created by Giperx on 2022/9/14.
//
#include <iostream>
#include <vector>
using namespace std;
// 矩阵置零
class Solution {
public:
    // O(m * n) 开两数组，分别记录行列是否发生变化
    void setZeroes(vector<vector<int>>& matrix) {
        int *row = new int[matrix.size()]();
        int *col = new int[matrix[0].size()]();

        for(int i = 0; i <matrix.size(); i ++){
            for(int j = 0; j < matrix[0].size(); j ++){
                if(!matrix[i][j]) row[i]++, col[j]++;
            }
        }

        //置零
        for(int i = 0; i < matrix.size(); i ++){
            for(int j = 0; j < matrix[0].size(); j ++){
                if(row[i] || col[j]) matrix[i][j] = 0;
            }
        }
    }
};
