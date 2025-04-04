class Solution{
public:
      vector<int> inorderTraversal(TreeNode* root){
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left!=NULL){
                TreeNode* pred= curr->left;
                while((pred->right!=NULL)&&(pred->right!=curr)){
                    pred=pred->right;
                }
                if(pred->right==NULL){
                    pred->right=curr;
                    curr=curr->left;
                }
                if(pred->right==curr){
                    pred->right=NULL;
                    cout<<curr->val<<" ";
                    curr=curr->right;
                }
            }
            else{
                cout<<cur->val<<" ";
                curr=curr->right;
            }
        }
      }
};