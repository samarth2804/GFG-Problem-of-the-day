# Insert an Element at the Bottom of a Stack #
# Problem Link: https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1

stack<int> insertAtBottom(stack<int> st,int x){
    stack<int> temp;
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }
    
    st.push(x);
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
    
    return st;
}