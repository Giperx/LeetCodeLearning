//
// Created by Giperx on 2022/9/12.
//
#include <vector>
#include <iostream>
using namespace std;
//买卖股票的最佳时机
class Solution {
public:
    //O(n)  一维dp
    // 前i天最大收益 = max（前i - 1天最大时间， 第i天价格 - 前i天最低价格）
    int maxProfit(vector<int>& prices) {
        int minp = 1e4 + 10, mon = 0;
        for(auto p: prices){
            if(p - minp > mon) mon = p - minp;
            if(p < minp) minp = p;
            //mon = max(mon, p - minp);
            //minp = min(minp, p);
        }
        return mon;
    }
};