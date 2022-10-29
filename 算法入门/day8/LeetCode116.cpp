//
// Created by Giperx on 2022/10/29.
//
#include <queue>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// 填充每个节点的下一个右侧节点指针
class Solution {
public:
    // O(n)  O(n) 层次遍历 bfs
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        queue<Node*> Q;
        Q.push(root);
        while (!Q.empty()) {
            int size = Q.size();
            for(int i = 0; i < size; i++) {
                Node* node = Q.front();
                Q.pop();
                if (i < size - 1) {
                    node->next = Q.front();
                }
                if (node->left != nullptr) {
                    Q.push(node->left);
                }
                if (node->right != nullptr) {
                    Q.push(node->right);
                }
            }
        }
        return root;
    }
};