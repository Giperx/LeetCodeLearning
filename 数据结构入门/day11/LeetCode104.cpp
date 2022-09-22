//
// Created by Giperx on 2022/9/18.
//
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
#include <iostream>
#include <queue>
using namespace std;
// 二叉树的最大深度
class Solution {
public:
    //O(n) O(height)   dfs  递归
    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    //O(n)   bfs    使用队列
    int maxDepth1(TreeNode* root) {
        if(!root) return 0;

        queue<TreeNode*> Q;
        Q.push(root);
        int ans = 0;
        while(!Q.empty()){
            int szs = Q.size();
            while(szs--){
                TreeNode* tmp = Q.front();
                Q.pop();
                if(tmp->left) Q.push(tmp->left);
                if(tmp->right) Q.push(tmp->right);
            }
            ans++;
        }
        return ans;
    }
};
