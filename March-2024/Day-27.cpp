# Find shortest safe route in a matrix # 
# Problem Link: https://www.geeksforgeeks.org/problems/find-shortest-safe-route-in-a-matrix/1

class Solution
{
public:
    void markUnsafePath(vector<vector<int>> &mat){
        int m=mat.size();
        int n=mat[0].size();
        
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(mat[i][j]==1){
                    if(i-1>=0 && mat[i-1][j]==0){
                        mat[i][j]=-1;
                    }
                    else if(j-1>=0 && mat[i][j-1]==0){
                        mat[i][j]=-1;
                    }
                    else if(i+1<m && mat[i+1][j]==0){
                        mat[i][j]=-1;
                    }
                    else if(j+1<n && mat[i][j+1]==0){
                        mat[i][j]=-1;
                    }
                }
            }
        }
    }
    
    
    int findShortestPath(vector<vector<int>> &mat)
    {
        int m=mat.size();
        int n=mat[0].size();
        if(n==1){
            return 1;
        }
        markUnsafePath(mat);
        
        queue<pair<int,int>> q;
        for(int i=0;i<m;++i){
            if(mat[i][0]==1){
             q.push({i,0}); 
             mat[i][0]=-1;
            }
        }
        
        int pathLen=1;
        int d[]={0,-1,0,1,0};
        
        while(!q.empty()){
            int n1=q.size();
            for(int i=0;i<n1;++i){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                
                for(int j=0;j<4;++j){
                    int nr=r+d[j];
                    int nc=c+d[j+1];
                    if(nr>=0 && nc>=0 && nr<m && nc<n && mat[nr][nc]==1){
                        if(nc==n-1){
                          return pathLen+1;
                        }
                        q.push({nr,nc});
                        mat[nr][nc]=-1;
                    }
                }
            }
            
            pathLen++;
        }
        
        return -1;
    }
};