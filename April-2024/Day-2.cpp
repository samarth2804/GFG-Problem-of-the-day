# Minimum Absolute Difference In BST #
# Problem Link: https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1

void help(Node* root, vector<int> &inorder){
    if(!root) return ;   
    help(root->left,inorder);
    inorder.push_back(root->data);
    help(root->right,inorder);
}

int absolute_diff(Node *root)
{
    vector<int> inorder;
    help(root,inorder);  
    int mini=INT_MAX , n=inorder.size();
    for(int i=1;i<n;++i){
        mini=min(mini,inorder[i]-inorder[i-1]);
    }
    return mini;
}