//
// Created by Giperx on 2022/9/16.
//
//  Definition for singly-linked list.
#include <iostream>
#include <unordered_map>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
// 环形链表
class Solution {
public:
    //O(n) O(n) 哈希表判断
    bool hasCycle(ListNode *head) {
        ListNode* pov = head;
       unordered_map<ListNode*, int> hash;
       //head可能就是空
       while(pov){
           if(hash.count(pov)) return true;
           else{
               hash.insert({pov, 1});
               pov = pov->next;
           }
       }
       return false;
    }

    //O(n) O(1) 快慢指针
    bool hasCycle2(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};