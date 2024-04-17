# Count Pairs in an Array #
# Problem Link: https://www.geeksforgeeks.org/problems/count-pairs-in-an-array4145/1


int merge(int *arr,int *temp,int st,int end){
    int mid=(st+end)>>1;
    int i=st,j=mid+1,ans=0,k=st;
    while(i<=mid && j<=end){
        if(arr[i] > arr[j]){
            ans+=(mid-i+1);
            temp[k++]=arr[j++];
        }
        else{
            //ans+=(j-mid-1);
            temp[k++]=arr[i++];
        }
    }
    
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=end){
        temp[k++]=arr[j++];
    }
    
    for(i=st;i<=end;++i){
        arr[i]=temp[i];
    }
    return ans;
}
int merge_sort(int *arr,int *temp,int st,int end){
    if(st>=end) return 0;
    
    int mid=(st+end)>>1;
    int ans=0;
    ans+=merge_sort(arr,temp,st,mid);
    ans+=merge_sort(arr,temp,mid+1,end);
    
    ans+=merge(arr,temp,st,end);
    return ans;
}

int countPairs(int arr[] , int n ) 
{
    for(int i=0;i<n;++i){
        arr[i]=i*arr[i];
    }
    
    int temp[n];
    for(int i=0;i<n;++i) temp[i]=arr[i];
    
    return merge_sort(arr,temp,0,n-1);
}