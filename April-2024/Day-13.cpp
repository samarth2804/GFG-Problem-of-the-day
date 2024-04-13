# Reverse Bits #
# Problem Link: https://www.geeksforgeeks.org/problems/reverse-bits3556/1

long long reversedBits(long long x) {
    long long ans=0;
    for(int i=0;i<32;++i){
        if(x &((long long)1<<i)){
            ans=ans|((long long)1<<(31-i));
        }
    }
    
    return ans;
}