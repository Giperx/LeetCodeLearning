//
// Created by Giperx on 2022/9/10.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//合并两个有序数组
class Solution{
public:
    //O(m + n)  双指针
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int *tmp = new int[m + n];
        int cnt = 0;
        for(int i = 0, j = 0; i < m && j < n;){
            if(!m) tmp[cnt++] = nums2[j];
            if(!n) tmp[cnt++] = nums1[i];
            if(nums1[i] <= nums2[j] ) tmp[cnt++] = nums1[i++];
            else tmp[cnt++] = nums2[j++];

            if(i == m) while(j != n) tmp[cnt++] = nums2[j++];
            if(j == n) while(i != m) tmp[cnt++] = nums1[i++];
        }

        for(int i = 0; i < m + n; i ++) nums1[i] = tmp[i];

    }

    //(m + n)log(m + n) 连接再sort
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n){
        for (int i = 0; i < n; ++i) {
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};