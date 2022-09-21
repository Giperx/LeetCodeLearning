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

// 二叉树的中后序遍历
class Solution {
public:
    void postorder(TreeNode* root, vector<int>& res){
        if(!root) return;
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
        return;
    }
    //O(n) O(n) 递归
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
};