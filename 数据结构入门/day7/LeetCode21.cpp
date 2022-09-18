//
// Created by Giperx on 2022/9/16.
//

//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// 合并两个有序链表
class Solution {
public:
    // O(m + n) O(1)    迭代，两个链表按顺序对比判断
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* tmp = new ListNode();
        ListNode* p1 = list1, *p2 = list2, *pre = tmp;

        while(p1 && p2){
            if(p1->val < p2->val){
                pre->next = p1;
                p1 = p1->next;
                pre = pre->next;
            }
            else{
                pre->next = p2;
                p2 = p2->next;
                pre = pre->next;
            }
        }
        if(!p1) pre->next = p2;
        else if(!p2) pre->next = p1;

        return tmp->next;
    }

    //O(m + n) O(m + n) 递归判断
    ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        else if(!list2) return list1;
        else if(list1->val < list2->val){
            list1->next = mergeTwoLists2(list1->next, list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists2(list1, list2->next);
            return list2;
        }
    }
};