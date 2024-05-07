// Reverse Level Order Traversal
// Problem Link:https://www.geeksforgeeks.org/problems/reverse-level-order-traversal/1

vector<int> reverseLevelOrder(Node *root)
{
     vector<int> result;
    stack <Node *> S; 
    queue <Node *> Q; 
    Q.push(root); 
    while (Q.empty() == false) 
    { 
        /* Dequeue node and make it root */
        root = Q.front(); 
        Q.pop(); 
        S.push(root); 
  
        /* Enqueue right child */
        if (root->right) 
            Q.push(root->right); // NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT 
  
        /* Enqueue left child */
        if (root->left) 
            Q.push(root->left); 
    } 
  
    // Now pop all items from stack one by one and print them 
    while (S.empty() == false) 
    { 
        root = S.top(); 
        result.push_back(root->data);
        S.pop(); 
    } 
    return result;
}