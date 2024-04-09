# Minimum Points To Reach Destination #
# Problem Link: https://www.geeksforgeeks.org/problems/minimum-points-to-reach-destination0540/1

int minPoints(int m, int n, vector<vector<int>> dungeon) 
{ 
    vector<vector<int>> dp(m,vector<int> (n));
    for(int i=m-1;i>=0;--i){
        for(int j=n-1;j>=0;--j){
            int maxi=INT_MIN;
            if(j<n-1){
                maxi=dp[i][j+1];
            }
            if(i<m-1){
                maxi=max(maxi,dp[i+1][j]);
            }
            if(maxi==INT_MIN) maxi=0;
            dp[i][j]=min(maxi+dungeon[i][j],0);
        }
    }

    return (1+abs(dp[0][0]));
} 