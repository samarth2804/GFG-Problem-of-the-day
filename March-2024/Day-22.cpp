# Diagonal sum in binary tree #
# Problem link: https://www.geeksforgeeks.org/problems/diagonal-sum-in-binary-tree/1

void help(Node *root,int diag, vector<int> &ans,int &n){
    if(diag==n){
        ans.push_back(root->data);
        n++;
    }
    else{
        ans[diag]+=root->data;
    }
    
    if(root->right){
        help(root->right,diag,ans,n);
    }
    
    if(root->left){
        help(root->left,diag+1,ans,n);
    }
}
    
vector <int> diagonalSum(Node* root) {
    vector<int> ans;
    if(root==nullptr) return ans;
    int n=0;
    help(root,0,ans,n);
    
    return ans;
}