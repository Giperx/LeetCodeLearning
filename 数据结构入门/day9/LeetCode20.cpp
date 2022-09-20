//
// Created by Giperx on 2022/9/20.
//
#include <iostream>
#include <vector>
using namespace std;
// 有效的括号
class Solution {
public:
    // O(n) O(n)    迭代特判
    bool isValid(string s) {
        vector<char> tmp;
        for(auto word: s){
            if(tmp.empty() || word == '(' || word == '{' || word == '[') tmp.push_back(word);
            else{
                if(word == ')' && tmp.back() == '('){
                    tmp.pop_back();
                    continue;
                }
                if(word == ']' && tmp.back() == '['){
                    tmp.pop_back();
                    continue;
                }
                if (word == '}' && tmp.back() == '{'){
                    tmp.pop_back();
                    continue;
                }
                return false;
            }
        }
        if(tmp.empty()) return true;
        else return false;
    }
};
