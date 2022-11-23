//
// Created by Giperx on 2022/11/23.
//
#include <iostream>
using namespace std;
// 颠倒二进制位
class Solution {
public:
    // O(k)  O(1) 循环
    uint32_t reverseBits1(uint32_t n) {
        uint32_t res = 0;
        uint32_t tmp = 1 << 31;
        for(int i = 0; i < 32; i ++){
            if((n & 1) == 1) res += tmp;
            n = n >> 1;
            tmp = tmp >> 1;
        }
        return res;
    }

    // O(1) O(1) 位运算分治
    uint32_t reverseBits(uint32_t n) {
        n = n >> 1 & M1 | (n & M1) << 1;
        n = n >> 2 & M2 | (n & M2) << 2;
        n = n >> 4 & M4 | (n & M4) << 4;
        n = n >> 8 & M8 | (n & M8) << 8;
        return n >> 16 | n << 16;
    }
private:
    const uint32_t M1 = 0x55555555;
    // 01010101010101010101010101010101
    const uint32_t M2 = 0x33333333;
    // 00110011001100110011001100110011
    const uint32_t M4 = 0x0f0f0f0f;
    // 00001111000011110000111100001111
    const uint32_t M8 = 0x00ff00ff;
    // 00000000111111110000000011111111
};