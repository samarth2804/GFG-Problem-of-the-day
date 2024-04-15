# Count the elements #
# Problem Link: https://www.geeksforgeeks.org/problems/count-the-elements1529/1

int help(vector<int> &b,int val){
    int i=0,j=b.size()-1;
    while(i<=j){
        int mid=(i+j)>>1;
        if(b[mid]<=val){
            i=mid+1;
        }
        else{
            j=mid-1;
        }
    }
    
    return i;
}

vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                            int q) {
    sort(b.begin(),b.end());
    vector<int> ans(q);
    for(int i=0;i<q;++i){
        int x=a[query[i]];
        ans[i]=help(b,x);
    }
    
    return ans;
}