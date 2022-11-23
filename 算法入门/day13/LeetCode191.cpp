//
// Created by Giperx on 2022/11/23.
//
#include <iostream>
using namespace std;
// λ1�ĸ���
class Solution {
public:
    // O(logn)  λ�����Ż�
    // n & (n - 1) �ɵ�n�����һλ1���0�����
    // 6(110) & 5(101) = 4(100)
    int hammingWeight(uint32_t n){
        int cnt = 0;
        while(n){
            cnt ++;
            n = n & (n - 1);
        }
        return cnt;
    }

    // ������λ�� �� ĩλ1
    int hammingWeight1(uint32_t n) {
        int cnt = 0;
        for(int i = 0; i < 32; i ++){
            if(n & 1) cnt ++;
            n = n >> 1;
        }
        return cnt;
    }


};