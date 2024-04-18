# Island Perimeter (Leetcode 463) #
# Problem Link: https://leetcode.com/problems/island-perimeter/submissions/1235915219/

int count=0, repeat=0;
for(int i=0;i<grid.size();i++)
{
    for(int j=0; j<grid[i].size();j++)
        {
            if(grid[i][j]==1)
            {
                count ++;
                if(i!=0 && grid[i-1][j] == 1) repeat++;
                if(j!=0 && grid[i][j-1] == 1) repeat++;
            }
        }
}
return 4*count-repeat*2;