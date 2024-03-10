//https://www.lanqiao.cn/problems/3513/learning/?page=2&first_category_id=1&tags=2023
#include<bits/stdc++.h>
#define MAX 51
using namespace std;
int T,m,n;
int vis[MAX][MAX],used[MAX][MAX];
int dx[]={1,-1,0,0,1,1,-1,-1};
int dy[]={0,0,1,-1,1,-1,1,-1};
string mp[MAX];
void bfs_col(int x,int y)
{
	queue<int> qx,qy;
	qx.push(x);
	qy.push(y);
	vis[x][y]=1;
	while(!qx.empty())
	{
		x=qx.front();
		qx.pop();
		y=qy.front();
		qy.pop();
		for(int i=0;i<4;i++)
		{
			int tx=x+dx[i];
			int ty=y+dy[i];
			if(tx<0||ty<0||tx>m-1||ty>n-1||vis[tx][ty]==1||mp[x][y]=='0')
			{
				continue;
			}
			qx.push(tx);
				qy.push(ty);
				vis[tx][ty]=1;
		}
	}
}
bool bfs_out(int x,int y)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			used[i][j]=0;
		}
	}
	queue<int>qx,qy;
	qx.push(x);
	qy.push(y);
	vis[x][y]=1;
		while(!qx.empty())
	{
		x=qx.front();
		qx.pop();
		y=qy.front();
		qy.pop();
		if(x==0||x==m-1||y==0||y==n-1)
		{
			return true;
		}
		for(int i=0;i<8;i++)
		{
			int tx=x+dx[i];
			int ty=y+dy[i];
			if(tx<0||ty<0||tx>m-1||ty>n-1||used[tx][ty]==1||mp[tx][ty]=='1')
			{
				continue;
			}
			qx.push(tx);
				qy.push(ty);
				used[tx][ty]=1;
		}
    }
    return false;
	
}
void solve()
{
	int ans=0;
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		cin>>mp[i];
		for(int j=0;j<n;j++)
		{
			vis[i][j]=0;
		}
	 } 
	 for(int i=0;i<m;i++)
	 {
	 	for(int j=0;j<n;j++)
	 	{
	 		if(!vis[i][j]&&mp[i][j]=='1')
	 		{
	 			bfs_col(i,j);
	 			if(bfs_out(i,j))//能走到边缘，说明是最外圈的岛
	 			{
	 				ans++;
				 }
			 }
		 }
	 }
	 cout<<ans<<endl;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}