//
// Created by Giperx on 2022/9/24.
//
#include <iostream>
#include <vector>
using namespace std;
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

// 二叉搜索树的最近公共祖先
class Solution {
public:
    //O(n) O(n)   遍历两次找到两节点路径存入vector，对比输入最后一个相同节点
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p = findPath(root, p);
        vector<TreeNode*> path_q = findPath(root, q);
        TreeNode* res;
        for(int i = 0; i < path_p.size() && i < path_q.size(); i ++){
            if(path_p[i] == path_q[i]) res = path_p[i];
            else break;
        }
        return res;
    }
    vector<TreeNode*> findPath(TreeNode* root, TreeNode* dist){
        vector<TreeNode*> res;
        TreeNode* tmp = root;
        while(tmp){
            res.push_back(tmp);
            if(tmp == dist) return res;
            else if(tmp->val < dist->val) tmp = tmp->right;
            else tmp = tmp->left;
        }
        return res;
    }

    //O(n) O(1) 将上述两次遍历过程合二为一，同时遍历判断
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        TreeNode* res = root;
        while(true){
            if(res->val > p->val && res->val > q->val) res = res->left;
            else if(res->val < p->val && res->val < q->val) res = res->right;
            else break;
        }
        return res;
    }
};