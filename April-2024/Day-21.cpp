// Three way partitioning
//Problem Link: https://www.geeksforgeeks.org/problems/three-way-partitioning/1

void threeWayPartition(vector<int>& array,int a, int b)
{
    int n=array.size();
    int i=0,j=0,k=n-1;
    
    while(j<=k){
        if(array[j] < a){
            swap(array[j],array[i]);
            ++i;
            ++j;
        }
        else if(array[j] > b){
            swap(array[j],array[k]);
            --k;
        }
        else{
            ++j;
        }
    }
}