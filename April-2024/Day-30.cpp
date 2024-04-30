// Add two numbers represented by linked lists
// Problem Link: https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

struct Node* reverseList(struct Node* head){
        Node* p=head, *q=nullptr, *r=nullptr;
        do{
            r=q;
            q=p;
            p=p->next;
            q->next=r;
            
        }while(p);
        
        return q;
    }
    
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
      if(!num1) return num2;
      if(!num2) return num1;
      
      num1=reverseList(num1);
      num2=reverseList(num2);
      
      Node *ans=new Node(0);
      Node *t=ans;
      int r=0,sum=0;
      while(num1 || num2 || r){
          sum=r;
          if(num1){
              sum+=num1->data;
              num1=num1->next;
          }
          if(num2){
              sum+=num2->data;
              num2=num2->next;
          }
          
          r=sum/10;
          sum=sum%10;
          t->next=new Node(sum);
          t=t->next;
      }
      
      ans=reverseList(ans->next);
      while(ans && ans->data==0){
          ans=ans->next;
      }
      
      if(!ans){
          return new Node(0);
      }
      return ans;
    }