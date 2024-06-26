// Print all nodes that don't have sibling
// Problem Link: https://www.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1

void noSibling_util(Node *root, set<int> &s)
{
    // Base case: if root is NULL, return
    if(root==NULL)
        return;
    
    // If the root has both left and right children, recursively call the function on both children
    if(root->left!=NULL and root->right!=NULL)
    {
        noSibling_util(root->left,s);
        noSibling_util(root->right,s);
    }
    
    // If the root has only a right child, insert its data into the set and call the function on the right child
    else if(root->right!=NULL)
    {
        s.insert(root->right->data);
        noSibling_util(root->right,s);
    }
    
    // If the root has only a left child, insert its data into the set and call the function on the left child
    else if(root->left!=NULL)
    {
        s.insert(root->left->data);
        noSibling_util(root->left,s);
    }
}

// Function to find nodes without a sibling in a binary tree and return them in a vector
vector<int> noSibling(Node *root)
{
    // Create an empty set to store the siblings
    set<int> s;
    // Create a vector to store the nodes without a sibling
    vector<int> res;

    // Call the utility function to identify the siblings
    noSibling_util(root,s);
    
    int flag=1;
    // Traverse the set and add the siblings to the result vector
    for(auto i=s.begin();i!=s.end();i++){
        res.push_back(*i);
        flag=0;
    }
    // If no sibling nodes were found, insert -1 into the result vector
    if(flag==1){
        res.push_back(-1);
    }
    // Return the result vector
    return res;
}
