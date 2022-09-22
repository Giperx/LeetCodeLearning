//
// Created by Giperx on 2022/9/21.
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
 // 二叉树的层序遍历
class Solution {
public:
    //O(n) O(n)   bfs, 用队列queue实现层次遍历
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res = {};
        if(root)    q.push(root);
        while(!q.empty()){
            int szs = q.size();
            vector<int> tmp;
            while(szs--){
                TreeNode* tmpTree = q.front();
                if(tmpTree->left) q.push(tmpTree->left);
                if(tmpTree->right) q.push(tmpTree->right);
                tmp.push_back(tmpTree->val);
                q.pop();
            }
            res.push_back(tmp);
        }
        return res;
    }
};
