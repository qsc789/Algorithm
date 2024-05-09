//https://www.matiji.net/exam/dohomework/6230/1
//码蹄集 运动会进行中
#include<bits/stdc++.h> 

using namespace std;
const int N=1e5+7;
int n;
int num[N];
int sum[N];
int l[N*2],r[N*2];
int ans=0;
int main( )
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
      cin>>num[i];
      if(num[i]==0)
      {
        num[i]=-1;//把女生的数字改为-1，方便计算
      }
      sum[i]=sum[i-1]+num[i];//前缀和
      int temp=sum[i]+n;//矫正为正数
      if(l[temp]==0)
      {
        l[temp]=i;//记录第一次出现这个数字的位置
      }
      else//已经出现过一次
      {
         r[temp]=i;
      }
    }
    for(int i=0;i<n*2;i++)
    {
        ans=max(ans,r[i]-l[i]);
    }
    cout<<ans<<endl;
    return 0;
}