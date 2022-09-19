//
// Created by Giperx on 2022/9/19.
//
//

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
#include <iostream>
using namespace std;
// 反转链表
class Solution {
public:
    //O(n) O(1) 迭代，用三个指针移动
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* pre = head;
        ListNode* op = head->next;

        pre->next = nullptr;
        while(op){
            ListNode* p3 = op->next;
            op->next = pre;
            pre = op;
            op = p3;
        }

        return pre;
    }

    //O(n) O(n) 递归
    ListNode* reverseList1(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* newHead = reverseList1(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
