# Strictly Increasing Array #
Problem Link: https://www.geeksforgeeks.org/problems/convert-to-strictly-increasing-array3351/1

int min_operations(vector<int>& arr) {
    int n=arr.size(), maxi=1;
    vector<int> dp(n,1);
    
    for(int i=1;i<n;++i){
        for(int j=0;j<i;++j){
            if(arr[i] > arr[j] && ((i-j) <= arr[i]-arr[j])){
                dp[i]=max(dp[i], 1+dp[j]);
            }
        }
        maxi=max(maxi, dp[i]);
    }
    
    return n-maxi;
}