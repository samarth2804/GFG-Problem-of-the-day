# Kth common ancestor in BST #
# Problem Link: https://www.geeksforgeeks.org/problems/kth-common-ancestor-in-bst/1

bool help(Node *root,int val,vector<int> &v){
    if(!root) return false;
    v.push_back(root->data);
    if(root->data == val) return true;
    if(help(root->left,val,v)) return true;
    if(help(root->right,val,v)) return true;
    
    v.pop_back();
    return false;
}

int kthCommonAncestor(Node *root, int k,int x, int y)
{   
    vector<int> v1,v2;
    help(root,x,v1);
    help(root,y,v2);
    int mini=min(v1.size(), v2.size());
    
    //if(mini <k) return -1;
    int i=0;
    for(i=0;i<mini; ++i){
        if(v1[i]!=v2[i]){
            break;
        }
    }
    
    if(i<k) return -1;
    
    return v1[i-k];
}