//
// Created by Giperx on 2022/9/15.
//
#include <iostream>
#include <string>
using namespace std;
// 赎金信
class Solution {
public:
     // 暴力O(m * n)
     bool canConstruct(string ransomNote, string magazine) {

         bool *sta = new bool[magazine.size()]();

         for(int i = 0; i < ransomNote.size(); i ++){
             int j = 0;
             for(; j < magazine.size(); j ++){
                 if(magazine[j] == ransomNote[i] && !sta[j]) {
                     sta[j] = true;
                     break;
                 }
             }
             if (j == magazine.size()) return false;
         }

         return true;
     }
     //O(m + n) 哈希表存个数，遍历判断

    bool canConstruct2(string ransomNote, string magazine) {
        int sta[26] = {0};

        for(auto word: magazine){
            sta[word - 'a']++;
        }

        for(auto word: ransomNote){
            if(!sta[word - 'a']) return false;
            sta[word - 'a']--;
        }
        return true;
    }
};
