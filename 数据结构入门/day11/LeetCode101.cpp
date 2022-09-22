//
// Created by Giperx on 2022/9/22.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
// 对称二叉树
class Solution {
public:
    //O(n) O(n)   递归
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }

    bool check(TreeNode* t1, TreeNode* t2){
        if(!t1 && !t2) return true;
        if(!t1 || !t2) return false;
        if(t1->val == t2->val && check(t1->left, t2->right) && check(t1->right, t2->left))
            return true;
        else return false;
    }

    //O(n) O(n) 迭代，使用队列两两入队对比
    bool isSymmetric1(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);

        while(!q.empty()){
            TreeNode* u, *v;
            u = q.front(); q.pop();
            v = q.front(); q.pop();

            if(!u && !v) continue;
            if(!u || !v) return false;
            if(u->val != v->val) return false;
            q.push(u->left);
            q.push(v->right);
            q.push(u->right);
            q.push(v->left);
        }

        return true;
    }

};