# Maximize dot product #
# Problem Link: https://www.geeksforgeeks.org/problems/maximize-dot-product2649/1

int help(int ind1,int ind2,int n, int m,int a[], int b[], vector<vector<int>> &dp){
    if(ind1==n || ind2==m) return 0;
    if(dp[ind1][ind2] !=-1) return dp[ind1][ind2];
    int take=(a[ind1]*b[ind2]) + help(ind1+1,ind2+1,n,m,a,b,dp);
    int nottake=0;
    if((m-ind2) < (n-ind1)){
        nottake=help(ind1+1,ind2,n,m,a,b,dp);
    }
    
    return dp[ind1][ind2]=max(take,nottake);
}

int maxDotProduct(int n, int m, int a[], int b[]) 
{ 
    vector<vector<int>> dp(n,vector<int> (m,-1));
    return help(0,0,n,m,a,b,dp);
} 