#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void MaxMinNodePrint(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
        int sz = q.size();
        vector<int> levelNodes;
        for (int i = 0; i < sz; i++) {
            TreeNode* node = q.front();
            q.pop();
            levelNodes.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        if (level == 0) {
            cout << levelNodes.front() <<" ";  
        } else if (level % 2 == 0) {
            cout << *min_element(levelNodes.begin(), levelNodes.end()) <<" "; 
        } else {
            cout << *max_element(levelNodes.begin(), levelNodes.end()) <<" "; 
        }
        level++;
    }
}
int main() {
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->left->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(3);
    root->left->right->left = new TreeNode(5);
    root->left->right->right = new TreeNode(7);
    root->right->left->left = new TreeNode(9);
    root->right->left->right = new TreeNode(11);
    root->right->right->left = new TreeNode(13);
    root->right->right->right = new TreeNode(15);
    MaxMinNodePrint(root);
    return 0;
}