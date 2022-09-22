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

// 路径总和
class Solution {
public:
    //O(n) o(H) 递归
    bool hasPathSum1(TreeNode* root, int targetSum) {
        return add(root, targetSum, 0);
    }

    bool add(TreeNode* node, int targetSum, int cs){
        if(!node) return false;
        if(!node->left && !node->right && node->val == targetSum - cs) return true;

        return add(node->left, targetSum, cs + node->val)
               || add(node->right, targetSum, cs + node->val);
    }

    //O(n) O(n) bfs, 使用两个队列来实现广度优先遍历，一个存每层节点，一个存节点对应路径总和
    bool hasPathSum(TreeNode* root, int targetSum){
        if(!root) return false;

        queue<TreeNode*> qnd;
        queue<int> qsm;

        qnd.push(root);
        qsm.push(root->val);

        while(!qnd.empty()){
            TreeNode* tmp = qnd.front(); qnd.pop();
            int stm = qsm.front(); qsm.pop();
            if(!tmp->left && !tmp->right) {
                if(stm == targetSum) return true;
                else continue;
            }

            if(tmp->left){
                qnd.push(tmp->left), qsm.push(stm + tmp->left->val);
            }
            if(tmp->right){
                qnd.push(tmp->right), qsm.push(stm + tmp->right->val);
            }
        }

        return false;
    }
};