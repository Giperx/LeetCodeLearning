//
// Created by Giperx on 2022/9/17.
//
//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 移除链表元素
class Solution {
public:
    // O(n) O(1)    迭代判断，用一个虚拟头节点和定位指针顺序判断
    ListNode* removeElements(ListNode* head, int val) {
        //if(!head) return nullptr;
        ListNode* pre = new ListNode(-1, head);
        ListNode* pov = pre;

        while(pov->next){
            if(pov->next->val == val) {
                ListNode* tmp = pov->next;
                pov->next = pov->next->next;
                delete tmp;
            }
            else{
                pov = pov->next;
            }
        }
        head = pre->next;
        delete pre;
        return head;
    }

    // O(n) O(n)    递归
    ListNode* removeElements2(ListNode* head, int val) {
        if(!head) return nullptr; // 递归出口

        head->next = removeElements2(head->next, val);
        return head->val == val ? head->next : head;
    }
};
