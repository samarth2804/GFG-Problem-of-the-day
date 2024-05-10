// Combination Sum II
// Problem Link: https://www.geeksforgeeks.org/problems/combination-sum-ii-1664263832/1

class Solution{
public:
    // Function to recursively solve the problem by finding combinations
    // that sum up to the given target value
    void solve(int indx,vector<int>&a,int k,int n,vector<int> v,vector<vector<int>>&ans)
    {
        // If the combination sum equals the target, add it to the result
        if(k==0)
        {
            ans.push_back(v);
            return;
        }
        // If there are no more elements to consider or if the remaining
        // target value is negative, return
        if(indx==n || k<0) return;

        // Iterate through the remaining elements starting from the current position
        for(int i=indx;i<n;i++)
        {
            // Skip over duplicate elements to avoid duplicate combinations
            if(i!=indx && a[i]==a[i-1]) continue;
            // Add the current element to the combination
            v.push_back(a[i]);
            // Recursively solve for the remaining elements and target value
            solve(i+1,a,k-a[i],n,v,ans);
            // Remove the current element from the combination
            v.pop_back();
        }
    }

    // Function to find all combinations that sum up to the target value
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        // Sort the input array in non-decreasing order
        sort(arr.begin(),arr.end());
        vector<int> v;
        vector<vector<int>>ans;
        // Call the solve function to find the combinations
        solve(0,arr,k,n,v,ans);
        // Return the combinations that sum up to the target value
        return ans;
    }
};
