// Exit Point in a Matrix
// Problem Link: https://www.geeksforgeeks.org/problems/exit-point-in-a-matrix0905/1

vector<int> help(int i,int j,int dir,vector<vector<int>>& matrix,const int &n,const int &m){
    if(i==n || j==m || i<0 || j<0){
        if(i<0) return {0,j};
        else if(j<0) return {i,0};
        else if(i==n) return {i-1,j};
        else return {i,j-1};
    }
    
    if(matrix[i][j]==1){
        matrix[i][j]=0;
        dir=(dir+1)%4;
    }
    
    if(dir==0){
        return help(i,j+1,dir,matrix,n,m);
    }
    else if(dir==1){
        return help(i+1,j,dir,matrix,n,m);
    }
    else if(dir==2){
        return help(i,j-1,dir,matrix,n,m);
    }
    else{
        return help(i-1,j,dir,matrix,n,m);
    }
}

vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
    return help(0,0,0,matrix,n,m);
    
}