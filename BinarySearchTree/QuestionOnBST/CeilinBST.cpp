if (root == NULL) return -1;
int ceil=-1;
while(root){
    if(root->data==key){
        ceil=root->data;
        return ceil;
    }
    if(key>root->data){
        root=root->right;
    }
    else{
        ceil=root->data;
        root=root->left;
    }
}
return ceil;