//
// Created by Giperx on 2022/9/8.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;
//重塑矩阵
class Solution {
public:
    //
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

int main(){
   vector<int> tmp = {'1', '2', '3'};
   stack<int> s1;
   s1.push(1);
   s1.push(2);
   s1.top();
   int i = (1 + 3 + 1)/2;
   cout << i << endl;
   unordered_map<int, int> map1;
   map1[1] = 2;
   cout << map1[1] << endl;
   unordered_map<int, int> map2 = map1;
   map1[1] = 1;
    cout << map1[1] << endl;
   cout << map2[1] << endl;
    int *cnt1 = new int[26]();
    return 0;
}