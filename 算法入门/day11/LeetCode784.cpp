//
// Created by Giperx on 2022/11/7.
//
#include <vector>
#include <string>
using namespace std;
//字母大小写全排列
class Solution {
private:
    vector<int> pos; // 记录s中是字母的位置
    vector<int> path; // 路径
public:
    // O(n*2^n)  O(n*2^n) 递归 指数枚举
    char change(char tmp){
        if(tmp >= 'a') return tmp - 32;
        else return tmp + 32;
    }

    void dfs1(string &s, vector<string> &res, int cur){
        if(cur == pos.size()) {
            string tmp(s);
            for(auto x:path) {
                tmp[x] = change(tmp[x]);
            }
            res.emplace_back(tmp);
            return;
        }

        path.emplace_back(pos[cur]);
        dfs1(s, res, cur + 1); // 选
        path.pop_back(); // 恢复现场
        dfs1(s, res, cur + 1); // 不选

    }
    vector<string> letterCasePermutation1(string s) {
        for(int i = 0; i < s.size(); i ++) if(s[i] >= 'A') pos.emplace_back(i);

        vector<string> res;
        dfs1(s, res, 0);
        return res;
    }

    // O(n*2^n)  O(n*2^n) 递归 指数枚举 官方
    vector<string> letterCasePermutation(string s){
        vector<string> res;
        dfs(s, res, 0);
        return res;
    }

    void dfs(string& s, vector<string> &res, int cur){
        while(cur < s.size() && isdigit(s[cur])) cur++;

        if(cur == s.size()){
            res.emplace_back(s);
            return;
        }
        s[cur] ^= 32;
        dfs(s, res, cur + 1);
        s[cur] ^= 32;
        dfs(s, res, cur + 1);
    }
};