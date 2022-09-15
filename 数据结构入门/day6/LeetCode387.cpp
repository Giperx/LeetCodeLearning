//
// Created by Giperx on 2022/9/15.
//
#include <iostream>
#include <string>
using namespace std;
// 字符串中的第一个唯一字符
class Solution {
public:
    // string类的函数使用
    int firstUniqChar(string s) {
        // for(auto word : s)
        //     if (s.find(word) == s.rfind(word)) return s.find(word);
        // return -1;
        for(int i = 0; i < s.size(); i ++){
            int pos = s.find(s[i]);
            if(pos == s.rfind(s[i])) return pos;
        }
        return -1;
    }
};
