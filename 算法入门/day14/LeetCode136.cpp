//
// Created by Giperx on 2022/11/23.
//
#include <iostream>
#include <vector>
using namespace std;
// ֻ����һ�ε�����
class Solution {
public:
    // O(n) O(1)    ���^
    // ������� ������  a ^ b ^ a = a ^ a ^ b = b
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1; i < nums.size(); i ++){
            res = res ^ nums[i];
        }
        return res;
    }
};