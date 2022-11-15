//
// Created by Giperx on 2022/11/10.
//
// 爬楼梯
class Solution {
public:
    int cnt[50]{};
    int climbStairs1(int n) {
        if(n == 0 || n == 1 || n == 2) return n;
        if(cnt[n]) return cnt[n];
        cnt[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return cnt[n];
    }

    //O(n)  O(1)    滚动数组
    int climbStairs(int n){
        int p = 0, q = 0, r = 1;
        for(int i = 1; i <= n; i ++){
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};