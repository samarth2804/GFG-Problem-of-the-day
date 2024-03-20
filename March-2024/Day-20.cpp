# Sum of nodes on the longest path from root to leaf node #
Problem Link: https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

class Solution
{
public:
    int findHeight(Node *root){
        if(root==nullptr) return 0;
        
        int lh=0,rh=0;
        if(root->left){
            lh=findHeight(root->left);
        }
        if(root->right){
            rh=findHeight(root->right);
        }
        
        return 1+max(lh,rh);
    }
    
    
    int sumOfLongRootToLeafPath(Node *root)
    {
       if(root== nullptr) return 0;
       if(root->left==nullptr && root->right==nullptr) return root->data;
       
       int lh=0,rh=0;
       if(root->left){
           lh=findHeight(root->left);
       }
       if(root->right){
           rh=findHeight(root->right);
       }
       
       if(lh > rh){
           return root->data+sumOfLongRootToLeafPath(root->left);
       }
       else if(rh > lh){
           return root->data+sumOfLongRootToLeafPath(root->right);
       }
       else{
           return (root->data + max(sumOfLongRootToLeafPath(root->left), sumOfLongRootToLeafPath(root->right)));
       }
       
       return -1;
    }
};