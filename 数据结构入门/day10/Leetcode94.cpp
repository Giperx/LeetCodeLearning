//
// Created by Giperx on 2022/9/21.
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

// 二叉树的中序遍历
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res){
        if(!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
        return;
    }
    //O(n) O(n) 递归
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};