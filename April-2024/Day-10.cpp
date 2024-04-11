# Party of Couples #
# Problem Link: https://www.geeksforgeeks.org/problems/alone-in-couple5507/1

int findSingle(int n, int arr[]){
    int ans=0;
    for(int i=0;i<n;++i){
        ans=(ans^arr[i]);
    }
    
    return ans;
}