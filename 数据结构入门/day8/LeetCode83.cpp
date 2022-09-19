//
// Created by Giperx on 2022/9/19.
//

//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
#include <iostream>
using namespace std;
// 删除排序链表中的重复元素
class Solution {
public:
    // O(n) O(1)  迭代,用指针依次与后一节点对比判断
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p1 = head;
        while(p1 && p1->next){
            if(p1->val == p1->next->val){
                ListNode* del = p1->next;
                p1->next = p1->next->next;
                delete del;
            }
            else{
                p1 = p1->next;
            }
        }
        return head;
    }

    // O(n) O(n)  递归
    ListNode* deleteDuplicates1(ListNode* head) {
        if(!head) return head;

        ListNode *tmp = deleteDuplicates1(head->next);
        if(head->val == tmp->val && tmp) head->next = tmp->next;
        return head;
    }
};
