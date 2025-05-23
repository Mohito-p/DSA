
class Solution {
public:
    void trim(TreeNode* root, int low, int high){
        if(root==NULL) return;
        while(root->left!=NULL){
            if(root->left->val<low){
                root->left=root->left->right;
            }
            else if(root->left->val>high){
                root->left=root->left->left;
            }
            else break;
        }
        while(root->right!=NULL){
            if(root->right->val>high)
                root->right=root->right->left;
            else if(root->right->val<low){
                root->right = root->right->right;
            }
            else break;   
        }
        trim(root->left,low,high);
        trim(root->right,low,high);
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* dummy = new TreeNode(INT_MAX);
        dummy->left=root;
        trim(dummy,low,high);
        return dummy->left;
    }
};