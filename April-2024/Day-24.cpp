// Paths to reach origin
// Problem Link: https://www.geeksforgeeks.org/problems/paths-to-reach-origin3850/1

long long mod=1e9+7;
long long help(int x,int y,vector<vector<long long>> &dp){
    if(x==0 && y==0) return 1;
    if(x<0 || y<0) return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    
    return dp[x][y]=(help(x-1,y,dp)+help(x,y-1,dp))%mod;
}
int ways(int x, int y)
{
    vector<vector<long long>> dp(x+1,vector<long long> (y+1,-1));
    return help(x,y,dp);
}