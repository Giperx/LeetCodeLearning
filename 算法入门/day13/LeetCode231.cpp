//
// Created by Giperx on 2022/11/23.
//
#include <iostream>
using namespace std;
// 2的幂
class Solution {
public:
    //O(1)  O(1) 位运算
    // 1000
    // 0111
    bool isPowerOfTwo(int n){

        return n > 0 && (n & (n - 1)) == 0;
        //      n > 0 && ((1 << 30) % n) == 0
        // 也可判断是否为 2 的最大幂 的约数
    }

    // O(logn)  O(1) 暴力
    bool isPowerOfTwo1(int n) {
        // 零 特判
        if(!n) return n;

        while(n != 1) {
            int tmp = n / 2;
            if(tmp * 2 != n) return false;
            n /= 2;
        }

        if(n == 1) return true;
        else return false;

    }
};