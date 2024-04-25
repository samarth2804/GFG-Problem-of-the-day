// Longest Ideal Subsequence (Leetcode 2370)
// Problem Link: https://leetcode.com/problems/longest-ideal-subsequence/description/

int longestIdealString(string s, int k) {
    int n=s.size();
    vector<int> dp(26,0);
    int ans=1,temp,mini,maxi;
    for(int i=0;i<n;++i){
        temp=(int)(s[i]-'a');
        mini=max(0,temp-k);
        maxi=min(25,temp+k);
        int m=0;
        for(int j=mini;j<=maxi;++j){
            m=max(m,dp[j]);
        }
        dp[s[i]-'a']=m+1;
        ans=max(ans,m+1);
    }

    return ans;
}