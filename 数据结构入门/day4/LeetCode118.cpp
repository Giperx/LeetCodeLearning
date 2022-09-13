//
// Created by Giperx on 2022/9/13.
//
#include <iostream>
#include <vector>
using namespace std;
// 杨辉三角
class Solution {
public:
    // O(numRows^2) 动态规划
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);

        for(int cnt = 1; cnt <= numRows; cnt ++){
            res[cnt - 1].push_back(1); // 初始化

            for(int j = 1; j < cnt - 1; j ++){
                int tmp =  res[cnt - 2][j - 1] + res[cnt - 2][j];
                res[cnt - 1].push_back(tmp);
            }

            if(cnt > 1) res[cnt - 1].push_back(1); // 第2行以后，尾数初始化
        }

        return res;
    }
};