# Minimize the Difference #
# Problem Link: https://www.geeksforgeeks.org/problems/minimize-the-difference/1

int minimizeDifference(int n, int k, vector<int> &arr) {
    vector<int> maxi1(n),maxi2(n),mini1(n),mini2(n);
    int t1=INT_MIN, t2=INT_MAX;
    for(int i=0;i<n;++i){
        t1=max(t1,arr[i]);
        t2=min(t2,arr[i]);
        maxi1[i]=t1;
        mini1[i]=t2;
    }
    
    t1=INT_MIN, t2=INT_MAX;
    for(int i=n-1;i>=0;--i){
        t1=max(t1,arr[i]);
        t2=min(t2,arr[i]);
        maxi2[i]=t1;
        mini2[i]=t2;
    }
    
    int res=INT_MAX;
    for(int i=0;i<=n-k;++i){
        int ind1=i-1, ind2=i+k;
        t1=INT_MIN, t2=INT_MAX;
        if(ind1>=0) t1=maxi1[ind1];
        if(ind2<n)  t1=max(maxi2[ind2],t1);
        if(ind1>=0) t2=mini1[ind1];
        if(ind2<n)  t2=min(mini2[ind2],t2);
        res=min(res,t1-t2);
    }
    
    return res;
}