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

// 二叉树的前序遍历
class Solution {
public:
    void preorder(TreeNode* root, vector<int>& res){
        if(!root) return;

        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
        return;
    }
    //O(n) O(n) 递归
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
};
