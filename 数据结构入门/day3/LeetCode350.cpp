//
// Created by Giperx on 2022/9/11.
//
#include <unordered_map>
#include <iostream>
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
//两个数组的交集 II
class Solution {
public:
    //O(mlog(m) + nlog(n))  排序 + 双指针
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> tmp;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());


        for(int i = 0, j = 0; i < nums1.size() && j < nums2.size(); ){
            if(nums1[i] == nums2[j]) tmp.push_back(nums1[i++]), j++;
            else if(nums1[i] < nums2[j]) i++;
            else j++;
        }

        return tmp;
    }

    //O(m + n)  哈希表
    vector<int> intersect1(vector<int>& nums1, vector<int>& nums2){
        unordered_map<int, int> hash;
        vector<int> tmp;
        for (int i = 0; i < nums1.size(); ++i) {
            hash[nums1[i]] ++;

        }

        for (int i = 0; i < nums2.size(); ++i) {
            if (hash.count(nums2[i])){
                hash[nums2[i]]--;
                tmp.push_back(nums2[i]);
                if (!hash[nums2[i]]) {
                    hash.erase(nums2[i]);
                }
            }
        }
        return tmp;
    }
};