class Solution {
    //找出直接或间接与边缘相连的O
    int n,m;
public void solve(char[][] board) {
        n=board.length;//行数
        if(n==0)
        {
            return;
        }
        m=board[0].length;//列数
        for(int i=0;i<n;i++)
        {
            dfs(board,i,0);
            dfs(board,i,m-1);
        }
        for(int i=0;i<m-1;i++)
        {
            dfs(board,0,i);
            dfs(board,n-1,i);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='A'){
                    board[i][j]='O';
                }
                else if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
    }
public void dfs(char[][] board,int x,int y)
    {
        if(x<0||x>=n||y<0||y>=m||board[x][y]!='O'){
            return;
        }
        board[x][y]='A';//标记直接或间接与边缘相连的O
        dfs(board,x+1,y);
        dfs(board,x-1,y);
        dfs(board,x,y+1);
        dfs(board,x,y-1);
    }
}