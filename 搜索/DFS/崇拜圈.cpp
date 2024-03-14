//https://www.lanqiao.cn/problems/182/learning/?page=1&first_category_id=1&tags=DFS

#include <iostream>
using namespace std;
int a[2000000];
int vis[2000000];
int m, N, t;
void dfs(int x, int ans){
  if(vis[x])//看有没有遍历到这个编号
  {
      if(a[x] == a[t])//如果编号相同，则圈闭合
      {
          if(ans > m){
              m = ans;//更新ans
          }
      }
    return;
  }
      vis[x] = 1;
      dfs(a[x], ans + 1);
      vis[x] = 0;//恢复现场
}
int main()
{
   cin>>N;
   for(int i = 1; i <= N; i++){
     cin>>a[i];
   }
   for(int i = 1; i <= N; i++){
           t = i;//记录开头下标
        dfs(i, 0);
  }
  cout<<m;
  return 0;
}