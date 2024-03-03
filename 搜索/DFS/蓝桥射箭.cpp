#include<bits/stdc++.h>
using namespace std;

struct PII
{
	int first;
	int second;
};
const int N=30;
int rol[N];
int col[N];
int n;
bool flag[N][N];//标记是否走过
vector<PII> res;

//图路径搜索
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
bool check(int x,int y)//判断走过路径的箭是否与目标相同 
{
	if(x==n&&y==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(col[i]!=0||rol[i]!=0)
			{
				return false;
			}
		}
		for(int i=0;i<res.size();i++)
		{
			int x=res[i].first;
			int y=res[i].second;
			int sum=n*(x-1)+y-1;//算编号 
			cout<<sum<<" ";
		}
		cout<<endl;
		return false;//成功终止 
	 } 
	 return true;//继续搜索 
}
bool pd(int x2,int y2)
{
	if(flag[x2][y2]==1)
	{
		return 0;//已被走过 
	}
	else if(x2<1)
	return 0;
	else if(x2>n)
	return 0;
	else if(y2<1)
	return 0;
	else if(y2>n)
	return 0;
	else if(col[x2]<=0)
	return 0;
	else if(rol[y2]<=0)
	return 0;
	else 
	return 1;
}
void dfs(int x,int y)
{
	if(!check(x,y))
	{
		return ;
	}
	else
	{
		for(int i=0;i<4;i++)
		{
			int xt=dx[i]+x;
			int yt=dy[i]+y;
			if(!pd(xt,yt))
			{
				continue;//不符合要求，换方向 
			}
			else
			{
				flag[xt][yt]=true;//走这步
				col[xt]--;
				rol[yt]--;
				res.push_back({xt,yt});
				dfs(xt,yt);
				//搜索回溯后，没找到正确答案，恢复作案现场
				res.pop_back();
				flag[xt][yt]=false;
				col[xt]++;
				rol[yt]++;
				
			 } 
		}
	 } 
 } 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>rol[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>col[i];
	}
	flag[1][1]=true;
	col[1]--;
	rol[1]--;
	res.push_back({1,1});
	dfs(1,1);
	return 0;
	
 } 