// K distance from root
// Problem Link: https://www.geeksforgeeks.org/problems/k-distance-from-root/1

void KdistanceUtil(struct Node *root,int k,vector<int> &nodes){
    // Base Case
    if (root==NULL)  return;
    // if current node is at distance k from root, add it to the nodes vector
    if (k==0)
        nodes.push_back(root->data);
    // Recur for right subtree first, then left subtree
    KdistanceUtil(root->left, k-1,nodes);
    KdistanceUtil(root->right, k-1,nodes);
}

// Function to find nodes at distance k from root
vector<int> Kdistance(struct Node *root, int k)
{
    vector<int> nodes;
    // call the recursive utility function to get the nodes at distance k
    KdistanceUtil(root,k,nodes);
    // return the nodes vector
    return nodes;
}