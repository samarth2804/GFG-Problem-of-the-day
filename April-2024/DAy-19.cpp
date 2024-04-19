# Find missing in second array #
# Problem Link: https://www.geeksforgeeks.org/problems/in-first-but-second5423/1


vector<int> findMissing(int a[], int b[], int n, int m) 
{ 
    unordered_set<int> st;
    for(int i=0;i<m;++i){
        st.insert(b[i]);
    }
    
    vector<int> ans;
    
    for(int j=0;j<n;++j){
        if(st.find(a[j])==st.end()){
            ans.push_back(a[j]);
        }
    }
    
    return ans;
}