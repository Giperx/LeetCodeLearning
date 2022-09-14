//
// Created by Giperx on 2022/9/14.
//
#include <iostream>
#include <vector>
using namespace std;
// 有效的数独
class Solution {
public:
    // O(1) 空间换时间，遍历时用三个状态数组判断是否重复
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10] = {0}; //每行状态
        int col[9][10] = {0}; //每列状态
        int sma[3][3][10] = {0}; //每小九宫格状态

        for(int i = 0; i < 9; i ++){
            for(int j = 0; j < 9; j ++){
                if(board[i][j] == '.') continue;
                else{
                    int tmp = board[i][j] - '0';
                    if(row[i][tmp] || col[j][tmp] || sma[i / 3][j / 3][tmp])
                        return false; //重复
                    row[i][tmp]++;
                    col[j][tmp]++;
                    sma[i / 3][j / 3][tmp]++;

                }
            }
        }
        return true;
    }
};