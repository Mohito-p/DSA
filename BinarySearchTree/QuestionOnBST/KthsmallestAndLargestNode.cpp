//one approach
class Solution {
public:
//Space complexity O(N+H)
//Time Complexity O(Nlogk)
void inorder(TreeNode* root, priority_queue<int>& maxHeap, int k) {
    if (!root) return;
    inorder(root->left, maxHeap, k);
    maxHeap.push(root->val);
    if (maxHeap.size() > k) maxHeap.pop(); 
    inorder(root->right, maxHeap, k);
}
int kthSmallest(TreeNode* root, int k) {
    priority_queue<int> maxHeap; 
    inorder(root, maxHeap, k);
    return maxHeap.top(); 
}
};