//
// Created by Giperx on 2022/9/23.
//
#include <iostream>
#include <vector>
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

// 二叉搜索树中的插入操作
class Solution {
public:
    //O(n) O(n)   递归
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);

        if(val < root->val) root->left = insertIntoBST(root->left, val);
        else root->right = insertIntoBST(root->right, val);

        return root;
    }

    //O(n) O(1)   迭代
    TreeNode* insertIntoBST1(TreeNode* root, int val){
        if(!root) return new TreeNode(val);

        TreeNode* parent = root, *p = root;
        while(p){
            parent = p;
            p = val < p->val ? p->left : p->right;
        }
        if(val < parent->val) parent->left = new TreeNode(val);
        else parent->right = new TreeNode(val);

        return root;
    }
};
