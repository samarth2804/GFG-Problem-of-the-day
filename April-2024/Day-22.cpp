// Row with minimum number of 1's
// Problem Link: https://www.geeksforgeeks.org/problems/row-with-minimum-number-of-1s5430/1

int minRow(int n, int m, vector<vector<int>> a) {
    int ans=0;
    int mini=INT_MAX;
    for(int i=0;i<n;++i){
        int count=0;
        for(int j=0;j<m;++j){
            if(a[i][j]){
                count++;
            }
        }
        
        if(count < mini){
            mini=count;
            ans=i;
        }
    }
    
    return ans+1;
}