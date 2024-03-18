#level Order Travesal in Binary Tree #
#Problem Link : https://www.geeksforgeeks.org/problems/level-order-traversal/1

vector<int> levelOrder(Node* root)
{
      if(root == nullptr) return {};
      
      vector<int> ans;
      queue<Node*> q;
      q.push(root);
      
      while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        ans.push_back(temp->data);
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
      }
      
      return ans;
}