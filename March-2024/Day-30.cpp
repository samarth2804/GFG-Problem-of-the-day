# Minimum element in BST #
# Problem Link: https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1

int minValue(Node* root) {
    if(!root) return -1;
    if(root->left==nullptr) return root->data;
    
    return minValue(root->left);
}
