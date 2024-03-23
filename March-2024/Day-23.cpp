# Fibonacci series up to Nth term #
# Problem Link: https://www.geeksforgeeks.org/problems/fibonacci-series-up-to-nth-term/1

vector<int> Series(int n) {
    vector<int> ans(n+1);
    long long mod=1e9+7;
    ans[0]=0;
    ans[1]=1;
    for(int i=2;i<=n;++i){
        ans[i]=((long long)ans[i-1]+ans[i-2])%mod;
    }
    
    return ans;
}
