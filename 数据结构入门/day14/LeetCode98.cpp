//
// Created by Giperx on 2022/9/24.
//
#include <iostream>
#include <stack>
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

// 验证二叉搜索树
class Solution {
public:
    //O(n) O(n)   递归
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }

    bool valid(TreeNode* root, long long low, long long up){
        if(!root) return true;

        if(root->val <= low || root->val >= up) return false;
        return valid(root->left, low, root->val) && valid(root->right, root->val, up);
    }

    //O(n) O(n)   迭代，使用中序遍历，因为二叉搜索树中序遍历是有序的
    bool isValidBST1(TreeNode* root){
        stack<TreeNode*> s;
        long long pre = (long long) INT_MIN - 1;
        while(!s.empty() || !root){
            while(!root){
                s.push(root);
                root->left;
            }

            root = s.top(); s.pop();
            if(root->val <= pre){
                return false;
            }
            pre = root->val;
            root = root->right;
        }
        return true;
    }
};
