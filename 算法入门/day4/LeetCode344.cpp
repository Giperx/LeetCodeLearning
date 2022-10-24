//
// Created by Giperx on 2022/10/24.
//
#include <vector>
using namespace std;
// 反转字符串
class Solution {
public:
    //O(n) O(1) 双指针
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;
        while(l < r) swap(s[l++], s[r--]);
    }
};
