//https://leetcode.cn/problems/number-of-islands/description/
class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid)
    {
        int num1=grid.size();
        int num2=grid[0].size();
        grid[i][j]='0';//置0
       if(i-1>=0&&grid[i-1][j]=='1')
       {
           dfs(i-1,j,grid);
       }
       if(i+1<=num1-1&&grid[i+1][j]=='1')
       {
           dfs(i+1,j,grid);
       }
       if(j-1>=0&&grid[i][j-1]=='1')
       {
           dfs(i,j-1,grid);
       }
       if(j+1<=num2-1&&grid[i][j+1]=='1')
       {
           dfs(i,j+1,grid);
       }
    }
    int numIslands(vector<vector<char>>& grid) {
        int num1=grid.size();
        int num2=grid[0].size();
        int sum=0;
        for(int i=0;i<num1;i++)
        {
             for(int j=0;j<num2;j++)
        {
            if(grid[i][j]=='1')
            {
                sum++;
                dfs(i,j,grid);
            }
        }
        }
       
        return sum;
    }
};