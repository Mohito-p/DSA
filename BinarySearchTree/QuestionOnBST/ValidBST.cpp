
class Solution {
public:
   long long maxTree(TreeNode* root){
    if(root==NULL) return LLONG_MIN;
    return max((long long)(root->val),max(maxTree(root->left),maxTree(root->right)));
}
long long minTree(TreeNode* root){
    if(root==NULL) return LLONG_MAX;
    return min((long long)(root->val),min(minTree(root->left),minTree(root->right)));
}
bool isValidBST(TreeNode* root){
    if(root==NULL) return true;
    else if((long long)(root->val)<=maxTree(root->left)) return false;
    else if((long long)(root->val)>=minTree(root->right)) return false;
    return isValidBST(root->left) && isValidBST(root->right);
}
};
// using inorder traversal

class Solution {
public:
    void inorder(TreeNode* root,vector<int>& v){
    if(root==NULL) return;
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}
    bool isValidBST(TreeNode* root) {
        vector<int>v;    
        inorder(root,v);
        for(int i=1;i<v.size();i++){
            if(v[i]<=v[i-1]) return false;
        }
        return true;
    }
};
// using no extra space

class Solution {
public:
    TreeNode* prev=NULL;
    bool flag=true;
    void inorder(TreeNode* root){
    if(root==NULL) return;
    inorder(root->left);
    if(prev!=NULL){
        if(root->val<=prev->val){
            flag=false;
            return;
        }
    }
        prev=root;
    inorder(root->right);
}
    bool isValidBST(TreeNode* root){   
        inorder(root);
        return flag;
    }
};