# Xoring and Clearing #
# Problem Link: https://www.geeksforgeeks.org/problems/xoring-and-clearing/1

void printArr(int n, int arr[]) {
    for(int i=0;i<n;++i) cout<<arr[i]<<" ";
    
    cout<<endl;
}

void setToZero(int n, int arr[]) {
    memset(arr,0,4*n);
}

void xor1ToN(int n, int arr[]) {
    for(int i=0;i<n;++i) arr[i]^=i;
}