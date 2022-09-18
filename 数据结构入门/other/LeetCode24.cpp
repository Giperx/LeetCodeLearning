//
// Created by Giperx on 2022/9/18.
//
#include <iostream>
#include <vector>
using namespace std;
//两两交换链表中的节点
  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

//O(n) O(1)    迭代,用虚拟头节点和三个指针操作
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //if(!head || !head->next) return head;

        ListNode* tmp = new ListNode(-1, head);
        ListNode* pov = tmp;

        while(pov->next && pov->next->next){
            ListNode* p1 = pov->next;
            ListNode* p2 = pov->next->next;

            pov->next = p2;
            p1->next = p2->next;
            p2->next = p1;
            pov = p1;
        }

        head = tmp->next;
        delete tmp;
        return head;
    }

    //O(n) O(n) 递归
    ListNode* swapPairs1(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* newHead = head->next;
        head->next = swapPairs1(newHead->next);
        newHead->next = head;
        return newHead;
    }
};




