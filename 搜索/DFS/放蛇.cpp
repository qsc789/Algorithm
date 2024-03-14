//https://www.lanqiao.cn/problems/1022/learning/?page=1&first_category_id=1&tags=DFS
#include <iostream>
using namespace std;
int a[4][4];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int ans=0;
void dfs(int x,int y,int num)
{
  if(num==16)//16不是17，num==16就已经成立
  {
    ans++;
    return ;
  }
  
  for(int i=0;i<4;i++)
  {
    int tx=x+dx[i];
    int ty=y+dy[i];
    if(tx>=0&&ty>=0&&tx<4&&ty<4&&a[tx][ty]!=1)
    {
    	a[tx][ty]=1;
      dfs(tx,ty,num+1);
      a[tx][ty]=0;
    }
  }
  
}
int main()
{
 
  for(int i=0;i<4;i++)
  {
    for(int j=0;j<4;j++)
    {
      a[i][j]=1;//注意标记和恢复现场，不用初始化数组
      dfs(i,j,1);
      a[i][j]=0;
    }
  }
  cout<<ans;
  return 0;
}