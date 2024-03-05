//https://www.lanqiao.cn/courses/31015/learning/?id=1926967&compatibility=false
#include<iostream>
#include<string>
#include<queue>
#include<string.h>
using namespace std;
char a[40][60];
int dp[40][60];
int dx[4]={1,0,0,-1};
int dy[4]={0,-1,1,0};
char dir[4]={'D','L','R','U'};
struct point
{
	int x;
	int y;
};
queue<point> r;

bool check(int x,int y)
{
	if(x>0&&y>0&&x<=30&&y<=50&&a[x][y]=='0'&&dp[x][y]==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void bfs()
{
	memset(dp,-1,sizeof(dp));
	dp[30][50]=0;
		point temp;
temp.x=30;
temp.y=50;
r.push(temp);
	while(!r.empty())
	{
		int x=r.front().x;
		int y=r.front().y;
		r.pop();
		for(int i=0;i<4;i++)
		{
			int tx=x+dx[i];
			int ty=y+dy[i];
			if(check(tx,ty))
			{
				dp[tx][ty]=dp[x][y]+1;
				point p;
				p.x=tx;
                p.y=ty;
                r.push(p);
			}
		}
	
	}
}
int main()
{

	for(int i=1;i<=30;i++)
	{
		for(int j=1;j<=50;j++)
		{
			cin>>a[i][j];
		}
	}
	bfs();
	int x=1,y=1;
	string res;
	while(x!=30||y!=50)
	{
		for(int i=0;i<4;i++)
		{
			int tx=x+dx[i];
	    	int ty=y+dy[i];
		if(tx>0&&ty>0&&ty<=50&&tx<=30&&a[tx][ty]=='0'&&dp[tx][ty]==dp[x][y]-1)
		{
			x=tx;
			y=ty;
			res+=dir[i];
			break;
		}
		}
		
	}
	cout<<res<<endl;
	return 0;
 } 