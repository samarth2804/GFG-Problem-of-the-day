# Sum of Products #
# Problem Link: https://www.geeksforgeeks.org/problems/sum-of-products5049/1

long long pairAndSum(int n, long long arr[]) {
    long long  ans=0;
    for(int j=0;j<32;++j){
        long long temp=0;
        for(int i=0;i<n;++i){
            if(arr[i] & 1){
                ++temp;
            }
            arr[i]>>=1;
        }
        
        ans+=(((temp)*(temp-1))/2)*(1<<j);
    }
    
    return ans;
}
