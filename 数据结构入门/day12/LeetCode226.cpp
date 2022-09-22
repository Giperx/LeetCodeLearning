//
// Created by Giperx on 2022/9/22.
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

// 翻转二叉树
class Solution {
public:
    //O(n) O(n)   递归
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        if(!root->left && !root->right) return root;

        TreeNode* tmp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = tmp;

        return root;
    }


};