# ZigZag Tree Traversal #
# problem link: https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1 #

vector <int> zigZagTraversal(Node* root)
{
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    bool ltr=true;
    
    while(!q.empty()){
        int n=q.size();
        vector<int> temp(n);
        Node *t;
        for(int i=0;i<n;++i){
            t=q.front();
            q.pop();
            temp[i]=t->data;
            if(t->left){
                q.push(t->left);
            }
            if(t->right){
                q.push(t->right);
            }
        }
        
        if(ltr){
            for(int i=0;i<n;++i){
                ans.push_back(temp[i]);
            }
        }
        else{
                for(int i=n-1;i>=0;--i){
                ans.push_back(temp[i]);
            }
        }
        
        ltr=!ltr;
    }
    
    return ans;
}