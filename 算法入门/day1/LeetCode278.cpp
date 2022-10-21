//
// Created by Giperx on 2022/10/21.
//
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
// 第一个错误的版本
class Solution {
public:
    bool isBadVersion(int mid);
    //O(logn) O(1)
    int firstBadVersion(int n) {
        int l = 1, r = n;
        int mid = 0;
        while(l < r){
            mid = l + (r - l) / 2; // 防止溢出
            if(isBadVersion(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};