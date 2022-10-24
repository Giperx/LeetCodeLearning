//
// Created by Giperx on 2022/10/24.
//
#include <string>
using namespace std;
// 反转字符串中的单词
class Solution {
public:
    //O(n)  O(1)    双指针, 原地解法
    string reverseWords(string s) {
        int i = 0, j = 0;
        for(; j < s.size();){
            if(s[j] == ' ' || j == s.size() - 1){   // 遇到' ' 或者 到达尾部则开始反转
                int tmp = j - 1; // 词尾
                // 反转新单词首位置开始 到 当前j所指的' '的前一位置（词尾）
                if(j == s.size() - 1) tmp += 1; // j到尾部时特判，词尾 = j
                // 开始反转
                for(; i < tmp;){
                    swap(s[i++], s[tmp--]);
                }
                i = ++j; // 赋值为 新单词的 首位置
            }
            else j++;
        }
        return s;
    }
};