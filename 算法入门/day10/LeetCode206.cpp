//
// Created by Giperx on 2022/10/30.
//
#include <vector>
using namespace std;
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

// 反转链表
class Solution {
public:
    //O(n) O(1) 迭代，用三个指针移动
    ListNode* reverseList1(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* p1 = nullptr, *p2 = head, *p3 = head;
        while(p2){
            p3 = p3->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        return p1;
    }

    //O(n)  O(n)    递归
    ListNode* reverseList(ListNode* head){
        if(!head || !head->next) return head;

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};