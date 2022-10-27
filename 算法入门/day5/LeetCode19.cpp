//
// Created by Giperx on 2022/10/26.
//
// 删除链表的倒数第N个结点
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

class Solution {
public:
    // O(L)  O(1) 双指针，右指针r先移动n位置 使 左右指针差n，
    // 再同时右移至表尾，此时左指针在需要删除节点的前一位置
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* l = dummy, *r = dummy;
        int cnt = n;
        while(cnt--) r = r->next;

        while(r->next) l = l->next, r = r->next;

        ListNode* tmp = l->next;
        l->next = tmp->next;
        delete tmp;

        head = dummy->next;
        delete dummy;
        return head;
    }
};