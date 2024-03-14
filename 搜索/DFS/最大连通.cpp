//https://www.lanqiao.cn/problems/2410/learning/?page=2&first_category_id=1&tags=DFS
#include <iostream>
#include<string>
using namespace std;
string a[50];
int ans=0;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void dfs(int x,int y)
{
  ans++;
   for(int i=0;i<4;i++)
   {
     int tx=x+dx[i];
     int ty=y+dy[i];
     if(tx>=0&&ty>=0&&tx<30&&ty<60&&a[tx][ty]=='1')
     {
       a[tx][ty]='2';
       dfs(tx,ty);
       //a[tx][ty]='1';
     }
   }
}

int main()
{
  int res=0;
  for(int i=0;i<30;i++)
  {
    cin>>a[i];
  }
  for(int i=0;i<30;i++)
  {
    for(int j=0;j<60;j++)
    {
      if(a[i][j]=='1')
      {
        ans=0;
        a[i][j]='2';
        dfs(i,j);
        //a[i][j]='1';不要恢复现场，防止重复计数
        if(ans>res)
        {
          res=ans;
        }
      }
    }
  }
  cout<<res<<endl;
  //cout<<148;
  return 0;
}