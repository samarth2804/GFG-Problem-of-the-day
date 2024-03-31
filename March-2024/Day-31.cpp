# Closest Neighbour in BST
# Problem Link: https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1

int findMaxForN(Node* root, int n) {
    if(!root) return -1;
    
    if(root->key==n) return n;
    else if(root->key <  n){
        int x=findMaxForN(root->right,n);
        return (x==-1 ? root->key : x);
    }
    return findMaxForN(root->left,n);
}