# Gray to Binary equivalent #
# Problem Link: https://www.geeksforgeeks.org/problems/gray-to-binary-equivalent-1587115620/1


int grayToBinary(int n){
    if(n==0) return 0;
    int ans=n;
    int len=0;
    while(ans){
        ++len;
        ans=(ans>>1);
    }
    
    for(int i=len-1;i>=0;--i){
        if(( (ans & (1<<(i+1))) != ( (n & (1<<i))<<1) )){
            ans=(ans | (1<<i));
        }
    }
    
    return ans;
}