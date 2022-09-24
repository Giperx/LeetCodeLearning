//
// Created by Giperx on 2022/9/24.
//
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
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

// 两数之和IV - 输入二叉搜索树
class Solution {
public:
    unordered_set<int> set;
    //O(n) O(n)   dfs + 哈希表，边遍历边判断
    bool findTarget1(TreeNode* root, int k) {
        if(!root) return false;

        if(set.count(k - root->val)) return true;
        set.insert(root->val);

        return findTarget(root->left, k) || findTarget(root->right, k);
    }

    //O(n) O(n)   bfs + 哈希表
    bool findTarget2(TreeNode* root, int k){
        unordered_set<int> hash;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            if(hash.count(k - tmp->val)) return true;
            hash.insert(tmp->val);
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);

        }
        return false;

    }

    //O(n) O(n) 中序遍历存下递增序列，双指针判断
    vector<int> vec;
    void inorderTraversal(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        inorderTraversal(node->left);
        vec.push_back(node->val);
        inorderTraversal(node->right);
    }
    bool findTarget(TreeNode *root, int k) {
        inorderTraversal(root);
        int left = 0, right = vec.size() - 1;
        while (left < right) {
            if (vec[left] + vec[right] == k) {
                return true;
            }
            if (vec[left] + vec[right] < k) {
                left++;
            } else {
                right--;
            }
        }
        return false;
    }

};