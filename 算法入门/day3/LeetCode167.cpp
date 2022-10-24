//
// Created by Giperx on 2022/10/23.
//
#include <vector>
using namespace std;
// 两数之和 || 输入有序数组
class Solution {
public:
    // O(nlogn)   O(1) 遍历+二分
    vector<int> twoSum1(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size(); i ++){
            int rest = target - numbers[i];
            //二分查找
            int l = i + 1, r = numbers.size() - 1, mid = 0;
            while(l < r){
                mid = (l + r )/2;
                if(numbers[mid] == rest) return {i + 1, mid + 1};
                else if (numbers[mid] > rest) r = mid;
                else l = mid + 1;
            }
            if(numbers[l] == rest) return {i + 1, l + 1};
        }
        return {};
    }

    //O(n)  O(1)    双指针，缩减搜索解空间，首尾指针根据大小差往内移动
    vector<int> twoSum(vector<int>& numbers, int target){
        int i = 0, j = numbers.size() - 1;
        while(i < j){
            if(numbers[i] + numbers[j] == target) break;
            else if(numbers[i] + numbers[j] < target) i++;
            else j--;
        }
        return vector<int>{i + 1, j + 1};
    }
};