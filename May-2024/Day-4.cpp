// Construct Binary Tree from Inorder and Postorder
// Problem Link: https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

Node* helper(int inorder[],int inStart,int inEnd,int postorder[],int postStart,int postEnd, unordered_map<int,int> &position){
    if(inStart>inEnd){return nullptr;}

    Node *curr=new Node(postorder[postEnd]);
    if(inStart==inEnd){return curr;}

    int pos=position[curr->data];
    int nEle=pos-inStart;

    curr->left=helper(inorder,inStart,pos-1,postorder,postStart,postStart+nEle-1,position);
    curr->right=helper(inorder,pos+1,inEnd,postorder,postStart+nEle,postEnd-1,position);

    return curr;
}

Node *buildTree(int in[], int post[], int n) {
    unordered_map<int,int> position;
    for(int i=0;i<n;++i){
        position[in[i]]=i;
    }

    return helper(in,0,n-1,post,0,n-1,position);
}