# Print N-bit binary numbers having more 1s than 0s #
# Problem Link: https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1

class Solution{
public:	
string help(int num,int n)
{
   string s = bitset<15> (num).to_string();
   int count1=0,count0=0;
   for(int i=15-n;i<15;++i){
       if(s[i]=='1'){
           count1++;
       }
       else{
           count0++;
           if(count0 > count1) return "";
       }
   }
    
    return s.substr(15-n);
}

	vector<string> NBitBinary(int n)
	{
	    vector<string> ans;
	    if(n==1) return {"1"};
	    
	    int maxi=(1<<(n));
        for(int i=maxi-1;i>0;--i){
            string str=help(i,n);
            if(!str.empty()){
                ans.push_back(str);
            }
        }

        return ans;
	}
};