//
// Created by Giperx on 2022/9/18.
//
#include <iostream>
#include <vector>
using namespace std;
// 反转字符串
class Solution {
public:
    //O(N) O(1)
    void reverseString(vector<char>& s) {
        for(int i = 0; i < s.size() / 2; i ++){
            swap(s[i], s[s.size() - i - 1]);
        }
    }
};
