//
// Created by Giperx on 2022/10/25.
//
#include <iostream>
using namespace std;
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  // 链表的中间结点
class Solution {
public:
    // O(n) O(1)    单指针 遍历个数，取中间位置返回
    ListNode* middleNode1(ListNode* head) {
        ListNode* p = head;
        int cnt = 1;
        while(p->next){
            p = p->next;
            cnt++;
        }
        int mid = (2 + cnt) / 2;
        p = head;
        int i = 1;
        while(p)
            if(i == mid) return p;
            else p = p->next, i++;
        return nullptr;
    }

    // O(n) O(1)    快慢指针，快指针走2步，慢指针走1步，快指针到达nullptr时，慢指针到达中间ceil位置
    ListNode* middleNode(ListNode* head){
        ListNode* slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
