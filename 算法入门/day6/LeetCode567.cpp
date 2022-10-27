//
// Created by Giperx on 2022/10/27.
//
#include <string>
#include <vector>
using namespace std;
// 字符串的排列
class Solution {
public:
    // O(n+m+|L|)  O(1) 滑动窗口
    bool checkInclusion1(string s1, string s2) {
        int n = s1.size(), m = s2.size(), diff = 0;
        if(n > m) return false;

        int *cnt = new int[26]();
        for(int i = 0; i < n; i ++){
            cnt[s2[i] - 'a'] ++;
            cnt[s1[i] - 'a'] --;
        }
        for(int i = 0; i < 26; i ++)
            if(cnt[i] != 0) diff++;
        if(!diff) return true;

        for(int i = n; i < m; i ++){
            if(!cnt[s2[i] - 'a']){
                diff++;
            }
            cnt[s2[i] - 'a']++;
            if(!cnt[s2[i] - 'a']){
                diff--;
            }
            if(!cnt[s2[i - n] - 'a']){
                diff++;
            }
            cnt[s2[i - n] - 'a']--;
            if(!cnt[s2[i - n] - 'a']){
                diff--;
            }
            if(!diff) return true;
        }
        return false;
    }

    // O(n+m+|L|)   O(1)    双指针
    bool checkInclusion(string s1, string s2){
        int n = s1.size(), m = s2.size();
        if(n > m) return false;

        vector<int> cnt(26);
        for(int i = 0; i < n; i ++){
            cnt[s1[i] - 'a']--;
        }
        int l = 0, r = 0;
        for(; r < m; r++){
            int x = s2[r] - 'a';
            cnt[x] ++;
            while(cnt[x] > 0){
                cnt[s2[l] - 'a']--;
                l++;
            }
            if((r - l + 1) == n) return true;
        }
        return false;
    }
};