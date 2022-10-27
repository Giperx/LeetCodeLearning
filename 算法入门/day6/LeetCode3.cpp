//
// Created by Giperx on 2022/10/26.
//
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// 无重复字符的最长子串
class Solution {
public:
    // O(n^2)   O(n)    哈希map，暴力
    int lengthOfLongestSubstring1(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i ++){
            unordered_map<char, int> map;
            int tmp = 0, j = i;
            while(j < s.size()){
                map[s[j]]++;
                if(map[s[j]] > 1) break;
                j++, tmp++;
            }
            res = max(res, tmp);
        }
        return res;
    }

    // O(n)  O(|n|) 滑动窗口，双指针
    int lengthOfLongestSubstring(string s){
        int l = -1, r = -1, res = 0;
        int n = s.size();
        unordered_set<char> set;
        for(int i = 0; i < n; i ++){
            l++;
            if(l >= 1) set.erase(s[l - 1]);
            while(r + 1 < n && !set.count(s[r + 1])){
                set.insert(s[++r]);
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};