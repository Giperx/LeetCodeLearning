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

// 二叉搜索树中的搜索
class Solution {
public:
    //O(n) O(n)  递归
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return root;
        if(root->val == val) return root;

        return searchBST(root->val > val ? root->left : root->right, val);
    }

    //O(n) O(1)   迭代
    TreeNode* searchBST1(TreeNode* root, int val) {
        while(root){
            if(root->val == val) return root;
            else if (val < root->val) root = root->left;
            else root = root->right;
        }
        return nullptr;
    }
};
