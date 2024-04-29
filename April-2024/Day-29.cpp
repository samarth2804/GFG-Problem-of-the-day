// Remove every kth node
// Problem Link: https://www.geeksforgeeks.org/problems/remove-every-kth-node/1

Node* deleteK(Node *head,int k){
    if(k==1) return nullptr;
    int temp=1;
    Node *curr = head;
    while(curr){
        temp++;
        if(temp==k){
            if(curr->next){
                curr->next=curr->next->next;
            }
            temp=1;
        }
        curr=curr->next;
    }
    
    return head;
}