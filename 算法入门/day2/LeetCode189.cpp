//
// Created by Giperx on 2022/10/22.
//
#include <bits/stdc++.h>
using namespace std;
//轮转数组
class Solution {
public:
    //O(n)   O(1) 双指针    环状数组
//     //由于是起点到起点，说明本次绕行的总路程 = lcm(n, k) // n、k的最小公倍数

// 设该次绕行，要走a圈，途中经历b个元素。
// 总路程 = lcm(n, k) // n、k的最小公倍数
//       = a * n // 走了a圈，圈长为n
//       = b * k // 走了b步，步长为k
// b = lcm(n, k) / k // 可知(1) b不随起点变化而变化 (2) n一定可以整除b、b一定是n的因子
// 为了遍历所有n个元素，所以要走m次
// 且由于公理：两个数的乘积等于其最大公约数与最小公倍数的乘积，n*k = lcm(n, k) * gcd(n, k)
// 有m = n / b = gcd(n, k)
    int gcd(int m, int n){
        if(n > m) swap(m, n);
        return !n ? m : gcd(n, m % n);
    }
    void rotate1(vector<int>& nums, int k) {
        k = k % nums.size();
        int itera = gcd(k, nums.size()); // 循环次数
        for(int i = 0; i < itera; i ++){
            int pos = i, pre = i, preNum = nums[i];
            while(pos != pre){
                swap(preNum, nums[pos]);
                (pos += k) %= nums.size();
            }
            nums[pos] = preNum;
        }
    }

    //O(n)  O(1)    翻转数组
    // nums = "----->-->"; k =3
    // result = "-->----->";

    // reverse "----->-->" we can get "<--<-----"
    // reverse "<--" we can get "--><-----"
    // reverse "<-----" we can get "-->----->"
    // this visualization help me figure it out :)
    void reverse(vector<int>& nums, int l, int r){
        while(l < r){
            swap(nums[l], nums[r]);
            l++, r--;
        }
    }
    void rotate(vector<int>& nums, int k){
        if(nums.size() < 2) return;
        k = k % nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};