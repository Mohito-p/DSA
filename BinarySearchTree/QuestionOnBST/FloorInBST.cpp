class Solution{
    public:
        int floor(Node* root, int key) {
        if (root == NULL) return -1;
        int floor=-1;
        while(root){
            if(root->data==key){
                floor=root->data;
                return floor;
            }
            if(key<root->data){
                root=root->left;
            }
            else{
                floor=root->data;
                root=root->right;
            }
        }
        return floor;
        }
    };