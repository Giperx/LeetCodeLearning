//
// Created by Giperx on 2022/11/23.
//
#include <iostream>
using namespace std;
// 位1的个数
class Solution {
public:
    // O(logn)  位运算优化
    // n & (n - 1) 可得n的最后一位1变成0后的数
    // 6(110) & 5(101) = 4(100)
    int hammingWeight(uint32_t n){
        int cnt = 0;
        while(n){
            cnt ++;
            n = n & (n - 1);
        }
        return cnt;
    }

    // 暴力移位， 判 末位1
    int hammingWeight1(uint32_t n) {
        int cnt = 0;
        for(int i = 0; i < 32; i ++){
            if(n & 1) cnt ++;
            n = n >> 1;
        }
        return cnt;
    }


};