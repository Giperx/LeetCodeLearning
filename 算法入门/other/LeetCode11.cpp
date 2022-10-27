//
// Created by Giperx on 2022/10/24.
//
#include <vector>
using namespace std;
// 盛水最多的容器
class Solution {
public:
    //O(n)   O(1) 贪心，每次向内移动短板，保留局部最优解，舍去一般解，缩小解空间
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, res = 0;
        while(l < r){
            if(height[l] <= height[r]) res = max(res, (r - l) * height[l++]);
            else res = max(res, (r - l) * height[r--]);
        }
        return res;
    }
};