# Sum of all substrings of a number #
# Problem Link: https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1 

long long sumSubstrings(string s){
    long long ans=0, mod=1e9+7, n=s.size(), temp, res=0;
    for(long long i=0;i<n;++i){
        ans=(ans*10)%mod;
        temp=((long long)(s[i]-'0')*(i+1))%mod;
        ans=(ans+temp)%mod;   
        res=(res+ans)%mod;
    }
    
    return res;
}