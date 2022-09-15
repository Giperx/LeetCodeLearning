//
// Created by Giperx on 2022/9/15.
//
#include <iostream>
#include <string>
using namespace std;
// 有效的字母异位词
class Solution {
public:
    // O(m + n) 遍历两字符串，存入字符次数并判断
    bool isAnagram(string s, string t) {
        int sta[26] = {0};
        for(auto word: s){
            sta[word - 'a'] ++;
        }
        for(auto word: t){
            sta[word - 'a'] --;
            if(sta[word - 'a'] < 0) return false;
        }

        for(auto cnt: sta){
            if(cnt != 0) return false;
        }

        return true;
    }
};
